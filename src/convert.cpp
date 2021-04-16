#include <convert.hpp>

const char * PYTHONPATH = "../";

void convert(std::string pack_path, std::string id, std::string out_path) {
    setenv("PYTHONPATH", PYTHONPATH, 1);
    // PyObject *pName, *pModule, *pDict, *pFunc, *pValue, *presult;
    Py_Initialize();

    PyRun_SimpleString("from mc2obj.mc2obj import convert");

    // std::string pack_path = "minecraft/";
    // std::string id = "minecraft:redstone_torch[lit=true]";
    // std::string out_path = "../blockCache/";
    
    std::string func_str = "convert('" + pack_path + "','" + id + "','" + out_path + "')";
    
    PyRun_SimpleString(func_str.c_str());

    Py_Finalize();
}