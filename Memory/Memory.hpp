#include <cstdint>
#include <fstream>
typedef struct _RAM_T8

{
   struct _RAM_T8*   previous, next;
   unsigned long     base; 
   unsigned int      flags; 
   unsigned char*    mem;   
}RAM_T8;

typedef struct _RAM_T16

{
   struct _RAM_T8*   previous, next;
   unsigned long     base; 
   unsigned int      flags; 
   unsigned short*    mem;   
}RAM_T16;

typedef struct _RAM_T32

{
   struct _RAM_T32*   previous, next;
   unsigned long     base; 
   unsigned int      flags; 
   unsigned int*    mem;   
}RAM_T32;

typedef struct _RAM_T64

{
   struct _RAM_T64*   previous, next;
   unsigned long     base; 
   unsigned int      flags; 
   unsigned long long int*    mem;   
}RAM_T64;

typedef struct _VHDSKMAP // Map emulated RAM to harddisk or other storage; to be implemented soon...
{
  unsigned int * _FILEOFF;
  unsigned int CONTAINERS, SEGMENTS, PAGES, CONTEXT;
}VHDSKMAP;
