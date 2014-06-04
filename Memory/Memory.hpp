#include <cstdint>
#include <fstream>
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
const char *RDNCGN_MAP[] =
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
   struct _RAM_T8*   previous, next;
   unsigned long     base; 
   unsigned int      flags; 
   unsigned char*    mem;  
   bool v_pageable = 1;
}RAM_T8;

typedef struct _RAM_T16

{
   struct _RAM_T8*   previous, next;
   unsigned long     base; 
   unsigned int      flags; 
   unsigned short*    mem;   
   bool v_pageable = 1;
}RAM_T16;

typedef struct _RAM_T32

{
   struct _RAM_T32*   previous, next;
   unsigned long     base; 
   unsigned int      flags; 
   unsigned int*    mem;   
   bool v_pageable = 1;
}RAM_T32;

typedef struct _RAM_T64

{
   struct _RAM_T64*   previous, next;
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
