#include "texture.h"
#include <iostream>
#include <cassert>

Texture::Texture(const std::string& filename)
{
    if ((textureSurface = SDL_LoadBMP(filename.c_str())))
    {
        GLenum mode;
        switch (textureSurface->format->BytesPerPixel) {
            case 4: //TODO: ADD PNG SUPPORT (ALPHA)
                if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
                    mode = GL_RGBA;
                else
                    mode = GL_BGRA;
            break;

            case 3:
                if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
                    mode = GL_RGB;
                else
                    mode = GL_BGR;
            break;
        }
        glGenTextures(1, &m_texture);
        glBindTexture(GL_TEXTURE_2D, m_texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, textureSurface->format->BytesPerPixel, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);

        SDL_FreeSurface(textureSurface);
        std::cout << "Successfully loaded texture " << filename << std::endl;
    }
    else
    {
        std::cerr << "Error: Texture " << filename << " not found!" << std::endl;
    }

}

Texture::~Texture()
{
    glDeleteTextures(1, &m_texture);
}

void Texture::Bind(unsigned int unit)
{
    assert(unit >= 0 && unit <= 31);
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, m_texture);
}
