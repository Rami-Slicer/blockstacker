#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <string>


/**
 * @brief Messy C++ interface with the model reader module for python. It works?
 * 
 * @param pack_path Path to the top level of the resource pack
 * @param id 
 * @param out_path 
 */
void convert(std::string pack_path, std::string id, std::string out_path);