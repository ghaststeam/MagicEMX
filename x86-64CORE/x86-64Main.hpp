namespace CPU
{
  // All opcodes are listed alphabetically.
  const char *OpCodes =
  {
    // 16-bit opcodes:
    "0x37", // AAA - ASCII adjust, AL after ADD # 1.
    "0xD5", // AAD - ASCII adjust, AX before DIV # 2.
    "0xD4",  // AAM - ASCII adjust, AX after MUL # 3.
    "0x3F",  // AAS - ASCII adjust, AL after SUB # 4.
    "0x10",  // ADC - Add with carry # 5.
  }
}
