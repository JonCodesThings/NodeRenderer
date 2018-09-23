#include "Renderer.hpp"

Renderer::Renderer() : m_vertex_buffer(nullptr), m_index_buffer(nullptr), m_shader(nullptr) {};

Renderer::~Renderer() {}

void Renderer::bindBuffer(const Buffer& buffer)
{
    switch (buffer.getBufferType())
    {
        default:
            return;
        case BUFFER_TYPE::INDEX:
            unbindBuffer(BUFFER_TYPE::INDEX);
            m_index_buffer = &buffer;
            break;
        case BUFFER_TYPE::VERTEX:
            unbindBuffer(BUFFER_TYPE::VERTEX);
            m_vertex_buffer = &buffer;
            break;
    }
}

void Renderer::bindShader(const Shader& shader)
{
    unbindShader();
    m_shader = &shader;
}

void Renderer::unbindBuffer(BUFFER_TYPE type)
{
    switch (type)
    {
        default:
            return;
        case BUFFER_TYPE::INDEX:
            m_index_buffer = nullptr;
            break;
        case BUFFER_TYPE::VERTEX:
            m_vertex_buffer = nullptr;
            break;
    }
}

void Renderer::unbindShader()
{
    m_shader = nullptr;
}
