#ifndef BUFFER_HPP
#define BUFFER_HPP

/*!
Enum to specify buffer type.
author: Jonathan Duncanson
*/
enum class BUFFER_TYPE
{
    VERTEX,
    INDEX,
    FIXED
};

/*!
Enum to specify buffer usage.
author: Jonathan Duncanson
*/
enum class BUFFER_USAGE
{
    STATIC,
    DYNAMIC
};

/*!
Class to represent buffers.
author: Jonathan Duncanson
*/
class Buffer
{
    public:
        virtual ~Buffer();
        virtual void bind() const = 0;
        virtual void create(void* data, unsigned int data_element_count, unsigned int data_element_size, BUFFER_TYPE type, BUFFER_USAGE usage) = 0;
        const BUFFER_TYPE getBufferType() const;
        const BUFFER_USAGE getBufferUsage() const;
        virtual void release() = 0;
        virtual void unbind() const = 0;
        virtual void update(void* data) = 0;
    protected:
        void* m_data;
        unsigned int m_data_element_count, m_data_element_size;
        BUFFER_TYPE m_type;
        BUFFER_USAGE m_usage;
};

#endif // BUFFER_HPP
