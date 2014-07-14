#include <cstdint>
#include <fstream>
void Write8(const int &addr8, int datawidth);
void Write16(const int &addr16, int datawidth);
void Write32(const int &addr32, int datawidth);
void Write64(const int &addr64, int datawidth);
void Write32RDNGCNVERTEX(const int &VECTORADDR, int *vectorval, bool IS_SCHEDULED, bool V_MAPPABLE);
void Write32SGPRPOT(const int &MAP, bool V_MAPPABLE);
void ShiftVERTEX(bool SGPR_CLOCK, void*, bool V_MAPPABLE);
uint8_t *HEAP_SIZE = NULL; // Address to fixed heap memory for HLE kernel-mode
uint8_t *VRAM_SIZE = NULL; // To contain the address of GCN's range
const char *DS4_1MAP[] =
{
   "0x7CCFFEE", // Start
   "0X7D00000", // End
};
const char *VHDSK_MAP[] =
{
   "0x8BFFC0",
   "0X8BFFC9", // Mirrored
   "0X8FFCCC",
};
const char *RDNGCN_MAP[] =
{  
   "0x9CCFFDE", // Start
   "0x9FFFF00", // End
};
const char *VSOUND_MAP[] =
{
   "0x3FF000B", // Start
   "0x3FF0ABB", // End
};
const char *VBLURAYCNT_MAP[] =
{
   "0xFF550A",
   "0xFF55BF", // Mirrored
   "0xFF7000",
};
typedef struct _RAM_T8


{
   const char *_RAM_T8 = nullptr;
   unsigned long     base; 
   unsigned int      flags; 
   unsigned char*    mem;  
   bool v_pageable = 1;
}RAM_T8;


typedef struct _RAM_T16


{
   const char *_RAM_T16 = nullptr;
   unsigned long     base; 
   unsigned int      flags; 
   unsigned short*    mem;   
   bool v_pageable = 1;
}RAM_T16;


typedef struct _RAM_T32


{
   const char *_RAM_T32 = nullptr;
   unsigned long     base; 
   unsigned int      flags; 
   unsigned int*    mem;   
   bool v_pageable = 1;
}RAM_T32;


typedef struct _RAM_T64


{
   const char *_RAM_T64 = nullptr;
   unsigned long     base; 
   unsigned int      flags; 
   unsigned long long int*    mem;  
   bool v_pageable = 1;
}RAM_T64;


typedef struct _VHDSKMAP // Map emulated RAM to harddisk or other storage; to be implemented soon...
{
  unsigned int * _FILEOFF;
  unsigned int CONTAINERS, SEGMENTS, PAGES, CONTEXT;
  
}VHDSKMAP;
