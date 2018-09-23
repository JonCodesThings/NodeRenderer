#include "VertexDataLayout.hpp"

VertexDataLayout::VertexDataLayout() : m_stride(0), m_type(LAYOUT_TYPE::NONE)
{}

VertexDataLayout::~VertexDataLayout()
{}

void VertexDataLayout::addProperty(const char* name, const DataType type, const unsigned int size, const unsigned int count, const unsigned int offset, const bool normalised)
{
    switch(m_type)
    {
        default:
            break;
        case LAYOUT_TYPE::INTERLEAVED:
            m_properties.push_back(VertexProperty{name, type, size, count, offset, normalised});
            m_stride += size * count;
            break;
        case LAYOUT_TYPE::GROUPED:
            m_properties.push_back(VertexProperty{name, type, size, count, offset, normalised});
            m_stride = 0.0f;
    }


}

const LAYOUT_TYPE VertexDataLayout::getLayoutType() const
{
    return m_type;
}

const float VertexDataLayout::getStride() const
{
    if (m_type == LAYOUT_TYPE::INTERLEAVED)
        return m_stride;
    return 0.0f;
}

const std::vector<VertexProperty>& VertexDataLayout::getVertexProperties() const
{
    return m_properties;
}

void VertexDataLayout::setLayoutType(LAYOUT_TYPE type)
{
    m_type = type;
}
