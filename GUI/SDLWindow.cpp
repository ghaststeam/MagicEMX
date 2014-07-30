// A cross-platform GUI library will be used later.
#include "SDL/SDL.h"
#include "SDL_opengl.h"
#include "/AMDx86-64CORE/AMDx86-64.hpp"
#include "/Firmware/FlashBlobs.hpp"

int main(int argc, char* argv[]) 
{
    bool is = 1;
    bool dohard = 0;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_Window *PS4EMXWinMain = SDL_CreateWindow(
        "PS4 EMX",                  
        NULL,           
        NULL,           
        700,                               
        520,                               
        SDL_WINDOW_OPENGL                  
    );
    // Fixed SDL/OpenGL attributes
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 ); 
    SDL_GLContext CONTEXT = SDL_GL_CreateContext(PS4EMXWinMain);
    if(dohard == 0)
    SDL_Renderer *MainR = SDL_CreateRenderer(PS4EMXWinMain, -1, SDL_RENDERER_SOFTWARE);
    else
    SDL_Renderer *MainR = SDL_CreateRenderer(PS4EMXWinMain, -1, SDL_RENDERER_ACCELERATED);
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(PS4EMXWinMain);
    SDL_Event EV;
    if (PS4EMXWinMain == NULL) 
    {
        return 0;
    }
    while(is)
    {
    while(SDL_PollEvent(&EV))
    {
        if(EV.type == SDL_QUIT)
        {
        SDL_DestroyWindow(PS4EMXWinMain);
        SDL_Quit();
        }
    }
    }
    
    return 0;
}
