#include <iostream>
#include <SDL2/SDL.h>
#include "display.h"

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    Display display(640, 480, "OxiEngine x64");

    while (!display.isClosed())
    {
        display.Clear(0.0f, 0.44f, 0.56f, 1.0f);
        display.Update();
    }

    SDL_Quit();
    return 0;
}
