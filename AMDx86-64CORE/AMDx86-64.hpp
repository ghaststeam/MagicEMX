#include <cstdint>
// Using 2's complement, this makes memory addressing, reads, writes, etc., more modular
////////////
typedef uint64_t uQUAD;
typedef uint32_t uDOUBLE;
typedef uint16_t uWORD;
typedef uint8_t uBYTE;
typedef int64_t sQUAD;
typedef int32_t sDOUBLE;
typedef int16_t sWORD;
typedef int8_t sBYTE;
////////////
uDOUBLE FrequencyMain = 1700000000;
uWORD LastFrequency = 0;
uDOUBLE UpTick = 900000;
uWORD Def_PIT_Frequency = 65535;
uWORD Current_Cycle = 0;
uBYTE Cycles = 0;
uQUAD STACK_SIZE = 0;
uBYTE HALT_STATUS = 0;
uDOUBLE BOOT_JUMP = 0;
////////////
template <typename Register>
void InitRegisterValue(Register& value);
////////////
struct BaseInterrupts
{
  uBYTE ROMDBG;
  uBYTE SINGLESTEP;
  uBYTE NMI; //Probably never used in an emulator except for x87 exceptions.
  uBYTE OVERFLOW;
  uBYTE PRINTV;
  uBYTE SLEEPWAKE;
  uBYTE INVALID;
  uBYTE IRQONE;
  uBYTE IRQTWO;
} INTERRUPT;
///////////
///////////
void InitRegister();

//TODO: CPU cache is transparent to x86 programs.
bool CacheLookUp(uQUAD &address, bool typeS);
uBYTE CPU_Cache = 4;
uBYTE Cache_Types = 28;

//TODO: relies on little-endian.
union reg64
{
  struct
  {
    uBYTE l;
    uBYTE h;
  };
  uWORD w;
  uDOUBLE d;
  uQUAD q;
};

struct x87reg
{
  sWORD exp;
  uQUAD mmx; //Used for both x87 and MMX.
};

union ymmreg
{
  uQUAD q[4];
  uDOUBLE d[8];
  uWORD w[16];
  uBYTE b[32];
  float f[8];
  double df[4];
};

struct segdesc
{
  uQUAD base; //Can only be changed for FS and GS.
  uDOUBLE limit;
  uBYTE access;
};

struct Register_List
{
  reg64 R[16]; //R0-R7 equate to RAX, RCX, RDX, RBX, RSP, RBP, RSI, and RDI respectively.
  
  uWORD segs[8]; //CS, SS, DS, ES, FS, and GS in that order. 2 are unused for efficiency.
  segdesc segdescs[8];
  
  uWORD GDTR;
  uWORD IDTR;
  uWORD LDTR;
  uWORD TR;
  
  uQUAD CR[16];
  
  uQUAD RIP;
  
  uQUAD RFLAGS;
  
  //x87/MMX
  
  x87reg ST[8];
  
  uWORD x87_CW;
  uWORD x87_SW;
  uWORD x87_TW;
  
  //SSE/AVX
  uDOUBLE MXCSR;
  ymmreg YMM[16];
  
} REGISTER;

enum RegType
{
  BYTE, WORD, DWORD, QWORD, XMM, YMM
};

struct ModRM
{
  RegType srctype, dsttype;
  uBYTE *srcbyte;
  uBYTE *dstbyte;
  uWORD *srcword;
  uWORD *dstword;
  uDOUBLE *srcdword;
  uDOUBLE *dstdword;
  uQUAD *srcqword;
  uQUAD *dstqword;
  
  ymmreg *srcymm;
  ymmreg *dstymm;
}; 

const char *REG_SUB_TYPE[] =
{
  "NONE",
  "LOWBYTE",
  "HIGHBYTE"
  "FULL",
  "LOWORD"
  
};


const char *FLAGS[] =
{
  "Carry",
  "Parity",
  "Adjust",
  "Zero",
  "Sign",
  "Trap",
  "Interrupt",
  "Direction",
  "IO",
  "Overflow",
  "Nested",
  "/Reserved"
};

//TODO: Should probably merge Unreal mode with Protected mode, since unreal mode is
//just a glitch in protected mode to bypass the MMU. Also, what are DefaultMode and 16BitMode and who put them there?
const char *CPU_Operating_Mode[] =
{
  "LongMode",
  "UnrealMode",
  "ProtectedMode",
  "SYSMANMode",
  "RealMode",
  "16BitMode",
  "DefaultMode"
};
// The number of threads and synchronization between CPU cores for the processors
const char *Threads[] =
{
  "4SyncMod",
  "2SyncMod",
  "8SyncMod",
  "12SyncMod",
  "14SyncMod",
  "18SyncMod",
  "24SyncMod",
  "30SyncMod",
};


uQUAD ProgramCounter = 0xFFFFFFFFFFFFFFF0; //TODO: Making this start at the x86 reset vector for now. HLE may require changes to this.


struct operands_addressing
{
const char *operand[] =
{
"m8",
"m16",
"m32",
"m64",
"r8",
"r16",
"r32",
"r64",
"rAX",
"Base",
"Index",
"Scale",
"MOD",
"R/M",
};
};
const char *Opcodes[] =
{
"AAC",
"AAM",
"ADC",
"ADD",
"PUSH",
"PUSHA",
"POP",
"POPA",
"CALL",
"CMP",
"JMP",
"JNE",
"JNZ",
"JZ",
"CLI",
"INT",
"HLT",
"AND",
"CLD",
"CLC",
"CBW",
"CMC",
"DEC",
"INC",
"IMUL",
"ESC",
"MOV",
"NOP",
"NOT",
"LODSB",
"LODSW",
"PUSHF",
"POPF",
"OUT",
"IN",
"IRET",
"RET",
"ROR",
"ROL",
"LEA",
"LDS",
"LES",
"LOCK",
"MUL",
"NEG",
"TEST",
"SUB",
"XOR",
"STD",
"STI",
"WAIT",
"SHL",
"SHR",
"SBB",
"PUSHD",
"IMUL",
"JC",
"JB",
"WAIT",
"XCHG",
"CALLF",
"ENTER",
"LEAVE",
"MFENCE",
"LFENCE",
"SFENCE",
};
