#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>

class Shader
{
    public:
        Shader(const std::string&);

        void Bind();
        std::string LoadShader(const std::string&);
        void CheckShaderError(GLuint, GLuint, bool, const std::string&);
        GLuint CreateShader(const std::string&, GLenum);

        virtual ~Shader();
    private:
        static const unsigned int NUM_SHADERS = 2;
        Shader(const Shader& other) {}
        void operator=(const Shader& other) {}

        GLuint m_program;
        GLuint m_shaders[NUM_SHADERS];
};

#endif // SHADER_H
