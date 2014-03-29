// SCEI CXD90025G, also known as the "MediaCon", is a secondary ARM microprocessor in PS4
// Containing the ARM v7 and v8 mnemonics
// Threading parallelism between x86's 8-cores

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
