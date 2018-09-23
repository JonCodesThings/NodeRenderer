#include "Buffer.hpp"

Buffer::~Buffer() {}

const BUFFER_TYPE Buffer::getBufferType() const
{ return m_type; }

const BUFFER_USAGE Buffer::getBufferUsage() const
{ return m_usage; }
