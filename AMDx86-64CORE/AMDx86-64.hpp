#include <cstdint>
// Using 2's complement, this makes memory addressing, reads, writes, etc., more modular
typedef uint64_t uQUAD;
typedef uint32_t uDOUBLE;
typedef uint16_t uWORD;
typedef uint8_t uBYTE;
typedef int64_t sQUAD;
typedef int32_t sDOUBLE;
typedef int16_t sWORD;
typedef int8_t sBYTE;

uBYTE CPU_Cache = 4;

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
// The full list of ASCII-reference & recognized opcodes
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
// Will add the rest; operands and addressing modes compared with opcode later
};
