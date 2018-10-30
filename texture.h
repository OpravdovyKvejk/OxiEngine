#ifndef TEXTURE_H
#define TEXTURE_H


class Texture
{
public:
    Texture();
    virtual ~Texture();
private:
    Texture(const Texture& other) {}
    void operator=(const Texture& other) {}

};

#endif // TEXTURE_H
