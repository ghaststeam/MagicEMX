#include "/PS4EMX/MediaCon/MediaCon.hpp"
#include <fstream>
void readBIOS(); // Read flash dump header below, both in offset 0x0 and 0x3000
// Main magic number
const char *MainMagic[] =
{
"S",
"O",
"N",
"Y",
" ",
"C",
"O",
"M",
"P",
"U",
"T",
"E",
"R",
" ",
"E",
"N",
"T",
"E",
"R",
"T",
"A",
"I",
"N",
"M",
"E",
"N",
"T",
" ",
"I",
"N",
"C",
"."
};
// First part of "BIOS" loaded, C0000001
const char * MainBlob = NULL:
// Need CPU + main memory for next parts
