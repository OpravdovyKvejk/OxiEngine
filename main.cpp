#include <iostream>
#include <SDL2/SDL.h>
#include <ctime>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"

int main(int argc, char *argv[])
{
    std::cout << "Starting engine..." << std::endl;
    std::clock_t engineStart = std::clock();
    SDL_Init(SDL_INIT_EVERYTHING); //Init everything, probably boil down to individual features in the future
    Display display(640, 480, "OxiEngine x64 v0.1.1"); //Show 'x64'? Engine is x64 only.
    double duration = ((std::clock() - engineStart) / (double) CLOCKS_PER_SEC) * 1000;
    std::cout << "Engine started in " << duration << "ms" <<std::endl;

    Vertex vertices[] = { //Temp vertex array. Will load from file.
                        Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0, 1)),
                        Vertex(glm::vec3(-0.5, 0.5, 0), glm::vec2(0, 0)),
                        Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1, 1))
                        };
    Vertex vertices2[] = { //Ditto.
                        Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1, 1)),
                        Vertex(glm::vec3(0.5, 0.5, 0), glm::vec2(1, 0)),
                        Vertex(glm::vec3(-0.5, 0.5, 0), glm::vec2(0, 0))
                        };

    Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0])); //Make array length specification optional?
    Mesh mesh2(vertices2, sizeof(vertices2)/sizeof(vertices2[0]));
    Shader shader(".\\res\\testshader");
    Texture texture(".\\res\\texture.bmp");
    while (!display.isClosed() ) //Move this to Engine class
    {
        display.Clear(0.0f, 0.44f, 0.56f, 1.0f);
        shader.Bind();
        texture.Bind(0);
        mesh.Draw();
        mesh2.Draw();

        display.Update();
    }

    SDL_Quit();
    return 0;
}
