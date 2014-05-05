#include <gl/gl.h>
#include <GL/glut.h>
class Keyboard
{
public: 
Keyboard(bool Keys[10]);
~Keyboard(int &ObjKY);
};
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

