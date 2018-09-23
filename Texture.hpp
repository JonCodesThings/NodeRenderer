#ifndef TEXTURE_HPP
#define TEXTURE_HPP

/*!
Class to represent textures.
author: Jonathan Duncanson
*/
class Texture
{
public:
    virtual ~Texture();
    virtual void bind() = 0;
    virtual void release() = 0;
    virtual void unbind() = 0;
};

#endif // TEXTURE_HPP
