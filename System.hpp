#ifndef SYSTEM_HPP
#define SYSTEM_HPP

extern "C"
{
#include <image.h>
}

class Buffer;
class Shader;
class ShaderConstantData;
class Texture;
class VertexDataLayout;

Buffer* createBuffer();

Shader* createShader();

ShaderConstantData* createShaderConstantData();

Texture* createTexture(struct image* image);

VertexDataLayout* createVertexDataLayout();

#endif // SYSTEM_HPP
