#ifndef VERTEXDATALAYOUT_HPP
#define VERTEXDATALAYOUT_HPP

#include <vector>

#include <CommonTypes.hpp>

/*!
Enum used to define buffer layout types.
author: Jonathan Duncanson
*/
enum class LAYOUT_TYPE
{
    INTERLEAVED,
    GROUPED,
    NONE
};

/*!
Struct used to store vertex property information.
author: Jonathan Duncanson
*/
struct VertexProperty
{
    const char* name;
    DataType type;
    unsigned int size;
    unsigned int count;
    unsigned int offset;
    bool normalised;
};

/*!
Struct used to store vertex data layouts for buffers.
author: Jonathan Duncanson
*/
class VertexDataLayout
{
    public:
        VertexDataLayout();
        ~VertexDataLayout();
        void addProperty(const char* name, const DataType type, const unsigned int size, const unsigned int count, const unsigned int offset, const bool normalised);
        const LAYOUT_TYPE getLayoutType() const;
        const float getStride() const;
        const std::vector<VertexProperty>& getVertexProperties() const;
        void setLayoutType(LAYOUT_TYPE type);
    protected:
        std::vector<VertexProperty> m_properties;
        unsigned int m_stride;
        LAYOUT_TYPE m_type;
    private:
};

#endif // VERTEXDATALAYOUT_HPP
