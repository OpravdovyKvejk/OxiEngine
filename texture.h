#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <GL/glew.h>
#include <SDL2/SDL.h>

class Texture
{
    public:
        Texture(const std::string&);
        virtual ~Texture();

        void Bind(unsigned int);
    private:
        Texture(const Texture& other) {}
        void operator=(const Texture& other) {}

        SDL_Surface *textureSurface;
        GLuint m_texture;
};

#endif // TEXTURE_H
