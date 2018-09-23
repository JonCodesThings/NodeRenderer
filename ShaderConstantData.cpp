#include "ShaderConstantData.hpp"

#include <cstring>

ShaderConstantData::ShaderConstantData()
{}

ShaderConstantData::~ShaderConstantData()
{}

void ShaderConstantData::addConstant(const char* name, DataType type)
{
    for (auto constant : m_constants)
    {
        if (strcmp(constant.name, name) == 0)
            return;
    }

    m_constants.push_back({name, type, 0, nullptr});
}

const std::vector<ShaderConstant>& ShaderConstantData::getShaderConstants() const
{
    return m_constants;
}

const void ShaderConstantData::setData(const char* name, void* data)
{
    for (auto& constant : m_constants)
    {
        if (strcmp(constant.name, name) == 0)
        {
            constant.data = data;
            return;
        }
    }
}

const void ShaderConstantData::setStorageLocation(const char* name, unsigned int location)
{
    for (auto& constant : m_constants)
    {
        if (strcmp(constant.name, name) == 0)
        {
            constant.storage_location = location;
            return;
        }
    }
}
