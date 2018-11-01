#include <iostream>
#include <SDL2/SDL.h>
#include <ctime>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"

int main(int argc, char *argv[])
{
    std::cout << "Starting engine..." << std::endl;
    std::clock_t engineStart = std::clock();
    SDL_Init(SDL_INIT_EVERYTHING); //Init everything, probably boil down to individual features in the future
    Display display(640, 480, "OxiEngine x64 v0.1.8");
    double duration = ((std::clock() - engineStart) / (double) CLOCKS_PER_SEC) * 1000;
    std::cout << "Engine started in " << duration << "ms" <<std::endl;

    Mesh mesh(".\\res\\monkey3.obj");
    Shader shader(".\\res\\testshader");
    Texture texture(".\\res\\fur.bmp");
    //Camera camera(glm::vec3(0, 0, -4), 70.0f, display.getAspect(), 0.01f, 1000.0f, 0.1f);
    Camera camera(display.getAspect());
    Transform transform;

    float counter = 0.0f;
    int camRotDir = 0;
    int camRotDirV = 0;
    int camPosDir = 0;
    int camPosDirV = 0;
    std::cout << "Tip: Use the arrow keys to look around!" << std::endl;

    while (!display.isClosed() )
    {
        display.Clear(0.0f, 0.0f, 0.0f, 1.0f);

        transform.GetRot().y = counter;

        shader.Bind();
        shader.Update(transform, camera);
        texture.Bind(0);
        mesh.Draw();

        display.Update();

        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            switch (e.type)
            {
                case SDL_KEYDOWN:
                    switch (e.key.keysym.sym)
                    {
                        case SDLK_RIGHT: camRotDir = -1;
                            break;
                        case SDLK_LEFT: camRotDir = 1;
                            break;
                        case SDLK_UP: camRotDirV = 1;
                            break;
                        case SDLK_DOWN: camRotDirV = -1;
                            break;
                        case SDLK_w: camPosDirV = 360;
                            break;
                        case SDLK_s: camPosDirV = -180;
                            break;
                        case SDLK_a: camPosDir = 90;
                            break;
                        case SDLK_d: camPosDir = -90;
                            break;

                        case SDLK_ESCAPE: display.ShouldClose(true);
                            break;
                    }
                break;
                case SDL_KEYUP:
                    switch (e.key.keysym.sym)
                    {
                        case SDLK_RIGHT: if (camRotDir < 0) camRotDir = 0;
                            break;
                        case SDLK_LEFT: if (camRotDir > 0) camRotDir = 0;
                            break;
                        case SDLK_UP: if (camRotDirV > 0) camRotDirV = 0;
                            break;
                        case SDLK_DOWN: if (camRotDirV < 0) camRotDirV = 0;
                            break;
                        case SDLK_w: if (camPosDirV > 0) camPosDirV = 0;
                            break;
                        case SDLK_s: if (camPosDirV < 0) camPosDirV = 0;
                            break;
                        case SDLK_a: if (camPosDir > 0) camPosDir = 0;
                            break;
                        case SDLK_d: if (camPosDir < 0) camPosDir = 0;
                            break;
                    }
                break;
                case SDL_QUIT: display.ShouldClose(true);
                break;
            }
        }
        camera.AddRotation(glm::vec3(4 * glm::radians((float) camRotDirV), 0, 0));
        camera.AddRotation(glm::vec3(0, 4 * glm::radians((float) camRotDir), 0));
        if (camPosDir != 0) camera.MoveForward(glm::vec3(0, glm::radians((float) camPosDir), 0));
        if (camPosDirV != 0) camera.MoveForward(glm::vec3(0, glm::radians((float) camPosDirV), 0));

        counter += 0.05f;
    }

    SDL_Quit();
    return 0;
}
