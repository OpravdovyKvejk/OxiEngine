#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <string>


class Display
{
    public:
        Display(int, int, std::string);

        void Clear(float, float, float, float);
        void Update();
        bool isClosed();

        virtual ~Display();
    private:
        Display(const Display& other) {}
        void operator=(const Display& other) {}

        SDL_Window* m_window;
        SDL_GLContext m_glContext;
        bool shouldClose;
};

#endif // DISPLAY_H
