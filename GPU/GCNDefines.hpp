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
int *exec_mask = NULL;
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
