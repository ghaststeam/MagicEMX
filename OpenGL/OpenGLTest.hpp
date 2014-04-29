#include <GL/glew.h> // GLEW extension library for OpenGL compatibility
#include <GL/glut.h>
#include <gl/gl.h>
void CheckOpenGL()
{
bool supported;
glewInit();
if (glewIsSupported("GL_VERSION_3_3"))
{
supported = 1;
}
}
