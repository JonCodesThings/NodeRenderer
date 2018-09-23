#include "Model.hpp"

#include <string.h>
#include <iostream>
#include <iomanip>
#include <System.hpp>

Model::Model(struct model* model)
{
    m_vertex_buffer = createBuffer();
    //float* vertex_buffer_data = new float[(model->vertex_count * 3) + (model->tex_coord_count * 2) + (model->normal_count * 3)];
    float* vertex_buffer_data = (float*)malloc(sizeof(float) *((model->vertex_count * 3) + (model->tex_coord_count * 2) + (model->normal_count * 3)));
    m_vertex_count = model->vertex_count;

    memcpy(&vertex_buffer_data[0], model->vertices, sizeof(float) * model->vertex_count * 3);
    memcpy(&vertex_buffer_data[model->vertex_count * 3], model->tex_coords, sizeof(float) * model->tex_coord_count * 2);
    memcpy(&vertex_buffer_data[(model->vertex_count * 3) + (model->tex_coord_count * 2)], model->normals, sizeof(float) * model->normal_count * 3);

    m_vertex_buffer->create(vertex_buffer_data, (model->vertex_count * 3) + (model->tex_coord_count * 2) + (model->normal_count * 3), sizeof(float), BUFFER_TYPE::VERTEX, BUFFER_USAGE::STATIC);
    m_buffer_layout.setLayoutType(LAYOUT_TYPE::GROUPED);
    m_buffer_layout.addProperty("coord3d", FLOAT, sizeof(float), 3, 0, false);
    m_buffer_layout.addProperty("texcoord", FLOAT, sizeof(float), 2, sizeof(float) * model->vertex_count * 3, false);
    m_buffer_layout.addProperty("normal", FLOAT, sizeof(float), 3, sizeof(float) * ((model->vertex_count * 3) + (model->tex_coord_count * 2)), false);
    //delete[] vertex_buffer_data;
}

Model::~Model() {}

const Buffer& Model::getVertexBuffer() const
{
    return *m_vertex_buffer;
}

const unsigned int Model::getVertexCount() const
{
    return m_vertex_count;
}

const VertexDataLayout& Model::getVertexDataLayout() const
{
    return m_buffer_layout;
}
