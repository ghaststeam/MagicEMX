// SCEI CXD90025G, also known as the "MediaCon", is a secondary ARM microprocessor in PS4
// Containing the ARM v7 and v8 mnemonics
// Threading parallelism between x86's 8-cores

const char *VECTOR_TABLE[] =
{
0x00000000, // Reset
0x0000001C, // Undefined
0x00000018, // SI
0x00000014, // PF Abort
0x00000010, // Data Abort
0x0000000C, // Reserved
0x00000008, // IRQ 
0x00000004, // FIQ
};
unsigned short ENDIANNESS[] =
{
1, //Little
2 // Big
};

unsigned short ALUFLAGS[] =
{
1, // Unsigned
2, // Zero
3, // Carry
4, // Overflow
};
const char *ARM_Mode[] =
{
  "Thumb",
  "ARM",
  "User",
  "FIQ",
  "IRQ",
  "Supervisor",
  "Abort",
  "Undefined",
  "Hypervisor",
  "System",
  "Monitor",
  "Default",
};
}
const char *ThreadSync[] =
{
"2Thread6Thread",
"3Thread6Thread",
"4Thread6Thread",
"2ThreadNoSync",
"3ThreadNoSync",
"4ThreadNoSync",
};
const char *ARMOpcodes[] =
{
"ADC",
"ADD",
"AND",
"B",
"BIC",
"BL",
"BX",
"CDP",
"CMN",
"CMP",
"EOR",
"LDC",
"LDM",
"LDR",
"MCR",
// Will add rest with x86 opcodes
};
enum ARMRegisters
{
  r0 = 0,
  r1 = 0,
  r2 = 0,
  r3 = 0,
  r4 = 0,
  r5 = 0,
  r6 = 0,
  r7 = 0,
  r8 = 0,
  r9 = 0,
  r10 = 0,
  r11 = 0,
  r12 = 0,
  r13 = 0,
  r14 = 0,
  r15,
  cpsr,
  sprs
};
