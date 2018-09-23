cmake_minimum_required(VERSION 3.10)
project(NodeRenderer CXX)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

find_library(ASSETLIB assetlib PATHS ../..)
find_path(ASSETLIB_INCLUDE_DIR NAMES 
image.c image.h model.h obj_utils.c obj_utils.h png_utils.c png_utils.h
PATH_SUFFIXES assetlib/)

if(NOT ASSETLIB)
	message(FATAL_ERROR "Could not locate assetlib")
endif()
if (NOT ASSETLIB_INCLUDE_DIR)
	message(FATAL_ERROR "Could not locate assetlib include directory")
endif()

include_directories(${ASSETLIB_INCLUDE_DIR})

set(SOURCE_FILES
	Buffer.cpp
	Buffer.hpp
	CommonTypes.hpp
	Model.cpp
	Model.hpp
	Renderer.cpp
	Renderer.hpp
	Shader.cpp
	Shader.hpp
	ShaderConstantData.cpp
	ShaderConstantData.hpp
	System.hpp
	Texture.cpp
	Texture.hpp
	VertexDataLayout.cpp
	VertexDataLayout.hpp)

add_library(NodeRenderer STATIC ${SOURCE_FILES})
target_link_libraries(NodeRenderer ${ASSETLIB})
set_target_properties(NodeRenderer PROPERTIES PREFIX "")

