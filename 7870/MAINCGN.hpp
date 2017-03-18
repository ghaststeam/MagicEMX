short m_GPUcores = 1152; //Total cores in all CUs.
short m_GPUcus = 18; //64 CPU cores per compute unit.
short m_MemoryMapArea =
[
0x00E0000,
0x00E0001,
0x00E0002,
0x00E0003,
0x00E0004
]

namespace Radeon_GCN // PS4 GPGPU
{

void clock();
void firmware();
void init();
class CU1
{
struct CoresCUO
{
int Start_PC = 0;
void core_oneACK();
void ShaderProg();
void TEXTURE_TIER-R();
void TEXTURE_TIERz();
void PIXEL_SHADERProg();
void GEOMETRY_SHADERO();
void GEOMETRY_SHADERb();
void VERTEX_SHADERO();
void TEXTURE_FILLx();
void GP-REGO();
void GP-REGb();
void GP-REGc();
void LIGHTING_CALCULATION();
int parallelism-M()
int thread_mO();
void OFFLOAD_X(void* Tar1, void* Tar2);
void _Share_SHADERVertexO();
void _Share_SHADERVERTEXb();
void _Share_SHADERPixelO();
void _Share_SHADERPixelb();
void _Share_SHADERPixelc();
}
}
