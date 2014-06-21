#include "/PS4EMX/MediaCon/MediaCon.hpp"
#include "/PS4EMX/Memory/Memory.hpp"
#include <fstream>
std::ifstream Magic (ifstream::binary);
template<typename Size>
void PassMemoryLS(Size& size); // Once done with Memory.cpp soon, hopefully
void WriteMemoryLs(Size& size);
// Going to do this a different way
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
