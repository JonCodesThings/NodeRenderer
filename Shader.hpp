#ifndef SHADER_HPP
#define SHADER_HPP

#include <VertexDataLayout.hpp>
#include <ShaderConstantData.hpp>

/*!
Enum used to specify shader types.
author: Jonathan Duncanson
*/
enum class SHADER_TYPE
{
    VERTEX,
    RASTER
};

/*!
Class used to load, store and bind shaders.
author: Jonathan Duncanson
*/
class Shader
{
    public:
        Shader();
        virtual ~Shader();
        void addShaderConstant(const char* name, DataType type);
        virtual void bind() const = 0;
        void bindVertexProperties(const VertexDataLayout& properties);
        virtual bool createFromFile(const char* filepath, SHADER_TYPE type) = 0;
        void setShaderConstant(const char* name, void* data);
        virtual void unbind() const = 0;
        void unbindVertexProperties();
    protected:
        virtual void updateShaderConstants() = 0;
        const VertexDataLayout* m_vertex_properties;
        ShaderConstantData m_shader_constants;
};

#endif // SHADER_HPP
