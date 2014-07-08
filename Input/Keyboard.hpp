#include <gl/gl.h>
#include <GL/glut.h>
#include "PS4EMX/AMDx86-64CORE/AMDx86-64.hpp"
class Keyboard
{
public: 
Keyboard(bool Keys[10]);
~Keyboard(int &ObjKY);
};
struct callbacks
{
 int *MMIO_RANGE1;
 short Cycle_LN = 65535 / LastFrequency;
 const char *STATUS_FLAGS[] =
 {
   "ACK",
   "NO_VIB",
   "DATA",
   "BYTEPACK",
   "WORDPACK"
 };
}
enum Buttons
{
CROSS = 0x00;
SQUARE = 0x08;
CIRCLE = 0x10;
TRIANGLE = 0x18;
DLEFT = 0x20;
DRIGHT = 0x28;
DUP = 0x30;
DDOWN = 0x38;
LEFTSTICK = 0x40;
RIGHTSTICK = 0x48;
L1 = 0x50;
L2 = 0x58;
R1 = 0x60;
R2 = 0x68;
OPTION = 0x70;
};

