#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <string>


class Display
{
    public:
        Display(int, int, const std::string&);

        void Clear(float, float, float, float);
        void Update();
        bool isClosed()
        { return shouldClose; }
        void ShouldClose(bool close)
        { shouldClose = close; }

        int getWidth() { return width; }
        int getHeight() { return height; }
        float getAspect() { return (float) width / (float) height; }

        virtual ~Display();
    private:
        Display(const Display& other) {}
        void operator=(const Display& other) {}

        SDL_Window* m_window;
        SDL_GLContext m_glContext;
        bool shouldClose;

        int width;
        int height;
};

#endif // DISPLAY_H
