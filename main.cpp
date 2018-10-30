#include <iostream>
#include <SDL2/SDL.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING); //Init everything, probably boil down to individual features in the future

    Display display(640, 480, "OxiEngine x64"); //Show 'x64'? Engine is x64 only.
    Vertex vertices[] = { //Temp vertex array. Will load from file.
                        Vertex(glm::vec3(-0.5, -0.5, 0)),
                        Vertex(glm::vec3(0, 0.5, 0)),
                        Vertex(glm::vec3(0.5, -0.5, 0))
                        };
    Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0])); //Make array length specification optional?
    Shader shader(".\\res\\testshader");

    while (!display.isClosed() ) //Move this to Engine class
    {
        display.Clear(0.0f, 0.44f, 0.56f, 1.0f);
        shader.Bind();
        mesh.Draw();

        display.Update();
    }

    SDL_Quit();
    return 0;
}
