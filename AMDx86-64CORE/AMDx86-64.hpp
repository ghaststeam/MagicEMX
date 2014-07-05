#include <cstdint>
#include "PS4EMX/Memory/Memory.hpp"
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
uWORD UpTick = 900000;
uWORD Def_PIT_Frequency = 65535;
uWORD Current_Cycle = 0;
uBYTE Cycles = 0;
uQUAD STACK_SIZE = 0;
uBYTE HALT_STATUS = 0;
uDOUBLE BOOT_JUMP = 0;
////////////
template <typename Register>
template <typename PORT>
////////////
struct BaseInterrupts
{
  uBYTE ROMDBG;
  uBYTE SINGLESTEP;
  uBYTE NMI;
  uBYTE OVERFLOW;
  uBYTE PRINTV;
  uBYTE SLEEPWAKE;
  uBYTE INVALID;
  uBYTE IRQONE;
  uBYTE IRQTWO;
} INTERRUPT;
///////////
///////////
void InitRegister(NULL);
void InitRegisterValue(Register& value);
bool CacheLookUp(uQUAD &address, bool typeS);
uBYTE CPU_Cache = 4;
uBYTE Cache_Types = 28;
struct Register_List
{
  // 8-bit
  uBYTE AH;
  uBYTE AL;
  uBYTE CH;
  uBYTE CL;
  uBYTE DH;
  uBYTE DL;
  uBYTE BH;
  uBYTE BL;
  // 16-bit
  uWORD AX;
  uWORD CX;
  uWORD DX;
  uWORD BX;
  uWORD SP;
  uWORD BP;
  uWORD SI;
  uWORD DI;
  uWORD IP;
  // 32-bit
  uDOUBLE EAX;
  uDOUBLE ECX;
  uDOUBLE EDX;
  uDOUBLE EBX;
  uDOUBLE ESP;
  uDOUBLE EBP;
  uDOUBLE ESI;
  uDOUBLE EDI;
  uDOUBLE EFLAGS;
  uWORD EIP;
  // 64-bit
  uQUAD RAX;
  uQUAD RCX;
  uQUAD RDX;
  uQUAD RBX;
  uQUAD RSP;
  uQUAD RBP;
  uQUAD RSI;
  uQUAD RDI;
  uQUAD RIP;
  
  
} REGISTER;
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

uQUAD ProgramCounter = 0x00;

struct operands_addressing
{
const char *operand[] =
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
"MOD"
"R/M"
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

// Will add the rest; operands and addressing modes compared with opcode later
};
