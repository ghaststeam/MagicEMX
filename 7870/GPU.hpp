#include <opengl/opengl.h>
#include <thread>
#include <fstream>
#include </PS4EMX/7878/OpenGLRenderer.hpp>
class GPU
{
  public GPU
  {
  GPU(int &readsz, int &buffsz, int &memsz);
  ~GPU();
  void InitFPS();
  void setshader(bool ca, int &i);
  }
}; GPU Gpu;
Gpu::setshader(bool ca, int &i)
{
thread UV_Pol (Con_Sha-i, 55, 1.0);
}
Gpu::InitFPS()
{
 bool FPSloop = 1;
 double lastTime = glfwGetTime();
 int frames = 0;
 do{

     double currentTime = glfwGetTime();
     frames++;
     if ( currentTime - lastTime >= 1.0 )
     {
         printf("%f ms/frame\n", 1000.0/double(frames));
         frames = 0;
         lastTime += 1.0;
     }
     while(FPSloop);

}
