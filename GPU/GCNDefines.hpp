#include <GL/gl.h>
#include <thread>
#include "PS4EMX/AMDx86-64CORE/AMDx86-64.hpp"

///////////////////////
bool RendererIsOn = 0;
bool ExtResFBO = 0;
//////////////////////
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
int *workitemprv = NULL;
int *workitemgrp = NULL;
int *SIMDops = NULL;
int *exec_mask1 = NULL;
int *exec_mask2 = NULL;
int *STATUS_CODE = NULL;
int *MODE_REGISTER_CODE = NULL;
int base_clock = 800000000;
short VGPRs[255]; 
short SGPRs[103];
short LDS[0x8000];
uQUAD TRAP_BASE_ADDRESS;
uQUAD TRAP_MEMORY_ADDRESS;
uDOUBLE TRAP_STATUS;
////////////////////
struct Conditions
{
 uBYTE SCALARS;
 uBYTE VECTORS;
 uBYTE MEMORY_DESCRIPTOR;
 uBYTE TRAP_EXCEPTION;
} CONDITION;
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
struct Render_FBORes
{
short *HQ_ModesDefine = NULL;
short FBO_Vertex;


} FBO_Mode;
static short screen_width = 1920;
static short screen_height = 1080;
int totalPCs = 1200;
static long int PC = 0;
/////////////////////////////////////////////////////////////////////
void SETPAIR_SGPR_PC(short &PAIRTYPE, int conditional);
void SWAP_PCADDR_SGPR(short &addrP);
void ColorDepthBuffer_WR(short &vertexop, void*, int microcode_es);
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
 // VOP3-only instructions
 "V_ADD_64",
 "V_MUL_64",
 // Logic instructions
 "V_CMP",
 "V_CMPX",
};
