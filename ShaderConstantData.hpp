#ifndef SHADERCONSTANTDATA_HPP
#define SHADERCONSTANTDATA_HPP

#include <vector>

#include <CommonTypes.hpp>

/*!
Struct used to store shader constant data information.
author: Jonathan Duncanson
*/
struct ShaderConstant
{
    const char* name;
    DataType type;
    unsigned int storage_location;
    void* data;
};

/*!
Class to store shader constants.
author: Jonathan Duncanson
*/
class ShaderConstantData
{
    public:
        ShaderConstantData();
        ~ShaderConstantData();
        void addConstant(const char* name, DataType type);
        const std::vector<ShaderConstant>& getShaderConstants() const;
        const void setData(const char* name, void* data);
        const void setStorageLocation(const char* name, unsigned int location);
    protected:
        std::vector<ShaderConstant> m_constants;
    private:
};

#endif // SHADERCONSTANTDATA_HPP
