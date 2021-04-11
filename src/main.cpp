#include <iostream>
#include <fstream>
// #include <nbt.hpp>
// #include <nbt++/io/stream_reader.h>
// #include <string>
#include <minecraft-file.hpp>

#include <voxelite.hpp>

const char * PYTHONPATH = "../";

#define PY_SSIZE_T_CLEAN
#include <Python.h>

// #include <nbtpp/nbt.hpp>

int main(int, char**) {
    setenv("PYTHONPATH", PYTHONPATH, 1);

    PyObject *pName, *pModule, *pDict, *pFunc, *pValue, *presult;

    namespace mc = mcfile;
    Py_Initialize();

    PyObject* module = PyImport_ImportModule("mc2obj.mc2obj");
    PyObject* convertFunc = PyObject_GetAttrString(module, "convert");

    PyObject* convertResult = PyObject_CallFunction(convertFunc, "minecraft/", "minecraft:redstone_torch[lit=true]", "blockCache/");
    
    

    std::shared_ptr<mc::Region> region = mc::Region::MakeRegion("../r.0.0.mca");
    std::cout << region->chunkExists(1, 2) << std::endl;
    std::shared_ptr<mc::Chunk> chunk = region->chunkAt(1, 2);

    init();

    World * world = getWorld();

    
    

    // std::ifstream f("../c.0.0.nbt", std::ifstream::binary);
    
    // nbtpp::nbt n(f);
    
    // n.debug();

    Py_Finalize();
    
    return 0;
}
