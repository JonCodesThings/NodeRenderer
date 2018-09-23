#ifndef MODEL_HPP
#define MODEL_HPP

extern "C"
{
#include <model.h>
}

#include <Buffer.hpp>
#include <VertexDataLayout.hpp>

/*!
Class to represent models.
author: Jonathan Duncanson
*/
class Model
{
    public:
        Model(struct model* model);
        ~Model();
        const Buffer& getVertexBuffer() const;
        const unsigned int getVertexCount() const;
        const VertexDataLayout& getVertexDataLayout() const;
    protected:
        Buffer* m_vertex_buffer;
        VertexDataLayout m_buffer_layout;
        unsigned int m_vertex_count;
    private:
};

#endif
