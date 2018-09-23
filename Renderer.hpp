#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <Buffer.hpp>
#include <Model.hpp>
#include <Shader.hpp>

/*!
Class designed to render specified meshes, models and buffers using shaders.
author: Jonathan Duncanson
*/
class Renderer
{
    public:
        Renderer();
        virtual ~Renderer();
        void bindBuffer(const Buffer& buffer);
        void bindShader(const Shader& shader);
        virtual void render() = 0;
        virtual void render(const Model& model) = 0;
        void unbindBuffer(BUFFER_TYPE type);
        void unbindShader();
    protected:
        const Buffer* m_vertex_buffer;
        const Buffer* m_index_buffer;
        const Shader* m_shader;
};

#endif // RENDERER_HPP
