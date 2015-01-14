#include <GL/gl.h>
#include <windows.h>
#include <thread>
#include "PS4EMX/AMDx86-64CORE/AMDx86-64.hpp"
// This class is for rendering the FBO (framebuffer-object) data to the actual OpenGL context/window
class FBOContext
{
 public:
 FBOContext(); // Default constructor
 FBOContext(HWND RHANDLE); // Constructor taking a HWND parameter for intialization of an OpenGL context
 protected:
 HWND RendererOut; // Handle to the renderer
 HDC RDC; // Handle to device context
 HGLRC HRC; // Handle to the rendering context
 PIXELFORMATDESCRIPTOR GCNFB; // Pixel info
};
///////////////////////
bool RendererIsOn = 0; // Whether to emulate the graphics with an OpenGL context yet
bool ExtResFBO = 0; // Extra Framebuffer Objects, specifically for non-PS4 graphics
//////////////////////
// All(most) all cache sizes, levels, channels, including texture caches
int cachesizeL1CH1;
int cachesizeL2CH1;
int TexCacheC1L1;
int TexCacheC2L1;
int TexCacheC3L1;
int TexCacheC4L1;
int TexCacheC1L2;
int TexCacheC2L2;
int TexCacheC3L2;
int TexCacheC4L2;
/////////////////////
int *workitemprv = NULL; // Pointer to a previous work-item thread (more later for debugging, perhaps?)
int *workitemgrp = NULL; // Pointer to a work-item group or "wavefront" for simulatenous execution threading
int *SIMDops = NULL; // Pointer to a reference for SIMD opcode mapping
int *exec_mask1 = NULL; // Pointer to the status of execution masks in execution of instruction flows
int *exec_mask2 = NULL; // Pointer to even more execution masks
int *STATUS_CODE = NULL; // Pointer to returned status codes from the GPU
int *MODE_REGISTER_CODE = NULL; // Pointer to conditional addressing mode+register code on conditional output
int base_clock = 800000000; // Base frequency speed for the GPU clock
short VGPRs[255]; // Every VGPR (vector-general-purpose-register) for SIMD
short SGPRs[103]; // Every SGPR (scalar-general-purpose-register) for SIMD
short LDS[0x8000]; // Local data share memory per compute-unit
short GDS[0x8000]; // Global date share memory for all wavefronts/CUs
uQUAD TRAP_BASE_ADDRESS; // 64-bit base address of the trap handler
uQUAD TRAP_MEMORY_ADDRESS; // 64-bit value representing the trap handler memory range
uDOUBLE TRAP_STATUS; // 32-bit value representing the status of the trap handler
////////////////////
// This struct represents the conditional operations to be taken by scalar/vector opcodes
struct Conditions
{
 uBYTE SCALARS;
 uBYTE VECTORS;
 uBYTE MEMORY_DESCRIPTOR;
 uBYTE TRAP_EXCEPTION;
} CONDITION;
///////////////////
// This struct represents the instruction flow of opcodes and related values
struct ControlFlow
{
 bool TERMINATE_PGM_WV;
 bool NO_OP_CT;
 uBYTE NO_OP_CT_MAX = 8;
 bool INIT_TRAP_HANDLER;
 bool RETURN_TRAP;
 const uBYTE TRAP_PRIORITY = 1;
 uWORD WAVEFRONT_SLEEP;
 uBYTE *MSG_INTERRUPT = NULL;
 bool UNCONDITIONAL_SET;
 uBYTE *SWAP_PC_SGPR = NULL;
 bool IGNORE_VECTOR_IN;
} CTRL;
///////////////////
// This struct represents capabilities for upscaling and bilinear interpolation/vertex custom-shading
struct Render_FBOResExt
{
short *HQ_ModesDefine = NULL;
short FBO_Vertex;
} FBO_Mode;

static short screen_width = 1920; // Internal X resolutions
static short screen_height = 1080; // Internal Y resolutions
int totalPCs = 1200; // All program counters and then some (for LLE)
/////////////////////////////////////////////////////////////////////

const char *GPU_REGS[] =
{
 // There are 256 vector registers and 104 scalar registers.
"VGPR1",
"VGPR2",
"VGPR3",
"VGPR4",
"VGPR5",
"VGPR6",
"VGPR7",
"VGPR8",
"VGPR9",
"VGPR10",
"VGPR11",
"VGPR12",
"SGPR1",
"SGPR2",
"SGPR3",
"SGPR4",
"SGPR5",
"SGPR6",
"SGPR7",
"SGPR8",
"SGPR9",
"SGPR10",
"SGPR11",
"SGPR12",
};
const char *SCALAR_INSTRUCTIONS[] =
{
 // There are also vector instructions, which can be microcode-formatted.
"S_ENDPGM",
"S_NOP",
"S_TRAP",
"S_RFE",
"S_SETPRIO",
"S_SLEEP",
"S_SENDMSG",
"S_BRANCH",
"S_BRANCH_TEST",
"S_SETPC",
"S_SWAPPC",
"S_GETPC",
"S_CBRANCH_FORK",
"S_CBRANCH_JOIN",
"S_SETVSKIP",
"S_BARRIER",
"S_WAITCNT",
"S_SETREG",
"S_GETREG",
"S_CBRANCH",
"S_CBRANCH_I/G_FORK",
"S_CBRANCH_JOIN",
"S_ADD_I32",
"S_ADD_U32",
"S_ADDC_U32",
"S_SUB_I32",
"S_SUB_U32",
"S_SUBB_U32",
"S_ABSDIFF_I32",
"S_MIN_I32",
"S_MIN_U32",
"S_MAX_I32",
"S_MAX_U32",
"S_MUL_I32",
"S_ADDK_I32",
"S_MULK_I32",
"S_ABS_I32",
"S_SEXT_I32_I8",
"S_SEXT_I32_I16",
};
const char *VECTOR_INSTRUCTIONS[] =
{
 // Three microcode formats: VOP1, VOP2, VOP3.
 "V_NOP",
 // VOP3-only instructions (I think)
 "V_ADD_64",
 "V_ADD_32"
 "V_MUL_64",
 "V_MUL_32",
 "V_ADD_64",
 "V_ADD_32",
 "V_SUB_64",
 "V_SUB_32",
 // Logic instructions
 "V_CMP",
 "V_CMPX",
};
// VECTOR FUNCTIONS
#define MICROEQ_VECT_NOP
// No operation
void VNOP();
#define MICROEQ_VECT_CMP_FLOAT32
// Compare two float-values from VGPRs
void VCF32(uDOUBLE &vecA, uDOUBLE &vecB);
#define MICROEQ_VECT_CMP_FLOAT64
// Compare two sets of 32-bit float values from VGPRS to combine two 32 bit float values to 64-bit
void VCF64(uDOUBLE &vecA1, uDOUBLE &vecA2, uDOUBLE &vecB1, uDOUBLE &vecB2);
#define MICROEQ_VECT_MUL_FLOAT32
// Multiply two float-values and return the sum in another register
void MF32(uDOUBLE &vecA, uDOUBLE &vecB, uDOUBLE &To, bool sign);
#define MICROEQ_VECT_MUL_FLOAT64
// Multiply two sets of 32-bit float values from VGPRs to combine two 32 bit float values to 64-bit
void MF64(uDOUBLE &vecA1, uDOUBLE &vecA2, uDOUBLE &vecB1, uDOUBLE &vecB2, uDOUBLE &To, bool sign);
#define MICROEQ_VECT_SUB_FLOAT32
// Subtract two float-values and return the sum in another register
void SF32(uDOUBLE &vecA, uDOUBLE &vecB, uDOUBLE &To, bool sign);
#define MICROEQ_VECT_SUB_FLOAT64
// Subtract two sets of 32-bit float values from VGPRs to combine two 32 bit float values to 64-bit
void SF64(uDOUBLE &vecA1, uDOUBLE &vecA2, uDOUBLE &vecB1, uDOUBLE &vecB2, uDOUBLE &To, bool sign);

