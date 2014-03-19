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
uQUAD ProgramCounter = 0;

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
// Will add the rest; operands and addressing modes compared with opcode later
};
