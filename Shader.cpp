#include "Shader.hpp"

Shader::Shader() : m_vertex_properties(nullptr) {}

Shader::~Shader() {}

void Shader::addShaderConstant(const char* name, DataType type)
{
    m_shader_constants.addConstant(name, type);
}

void Shader::bindVertexProperties(const VertexDataLayout& properties)
{
    m_vertex_properties = &properties;
}

void Shader::setShaderConstant(const char* name, void* data)
{
    m_shader_constants.setData(name, data);
    updateShaderConstants();
}

void Shader::unbindVertexProperties()
{
    m_vertex_properties = nullptr;
}
