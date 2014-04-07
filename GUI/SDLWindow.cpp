#include "SDL/SDL.h"
#include "/AMDx86-64CORE/AMDx86-64.hpp"
#include "/Firmware/FlashBlobs.hpp"

int main(int argc, char* argv[]) 
{
    bool is = 1;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *PS4EMXWinMain = SDL_CreateWindow(
        "PS4 EMX",                  
        NULL,           
        NULL,           
        700,                               
        520,                               
        SDL_WINDOW_OPENGL                  
    );

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
