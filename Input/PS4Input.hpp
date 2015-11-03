#include <gl/gl.h>
#include <GL/glut.h>
#include "PS4EMX/AMDx86-64CORE/AMDx86-64.hpp"
class Keyboard // A revised, C++-centric, objected-oriented re-construction is in need.
{
public: 
Keyboard(bool Keys);
~Keyboard();
};
struct callbacks
{
 // This needs some improvising of the control structure of the DS4.
 const char *STATUS_FLAGS[8]; // Semi-mock interrupts for status values of the DS4.
};
enum Buttons // Need to add share button, touch pad click, home button, and add axis to analog sticks
{
CROSS = 0x00,
SQUARE = 0x08,
CIRCLE = 0x10,
TRIANGLE = 0x18,
DLEFT = 0x20,
DRIGHT = 0x28,
DUP = 0x30,
DDOWN = 0x38,
LEFTSTICK = 0x40,
RIGHTSTICK = 0x48,
L1 = 0x50,
L2 = 0x58,
R1 = 0x60,
R2 = 0x68,
OPTION = 0x70,
SHARE = 0x78
};

