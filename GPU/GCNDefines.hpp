#include <GL/gl.h>
#include <thread>
void SetThread();
void SetInterpreter();
bool RendererIsOn = 0;
bool ExtResFBO = 0;
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
int *workitemprv = NULL;
int *workitemgrp = NULL;
int *SIMDops = NULL;
int *exec_mask = NULL;
struct Threading
{
 thread THREAD_CU (SetThread);
 thread FPU_SSRCOP (SetInterpreter);
} RDN_THREAD;
struct Render_FBORes
{
short *HQ_ModesDefine = NULL;
short FBO_Vertex;

} FBO_Mode;
static short screen_width = 1920;
static short screen_height = 1080;
extern static long long int PC = 0, 0, 0, 0;
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

} GPU_REG;

// Not useable; it needs a lot of work
