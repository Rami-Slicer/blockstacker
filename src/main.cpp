#include <iostream>
#include <fstream>
// #include <nbt.hpp>
// #include <nbt++/io/stream_reader.h>
// #include <string>
#include <minecraft-file.hpp>

#include <voxelite.hpp>
#include <convert.hpp>





// #include <nbtpp/nbt.hpp>

int main(int argc, char *argv[]) {
    namespace mc = mcfile;

    std::shared_ptr<mc::Region> region = mc::Region::MakeRegion("../r.0.0.mca");
    // std::cout << region->chunkExists(1, 2) << std::endl;
    std::shared_ptr<mc::Chunk> chunk = region->chunkAt(1, 2);

    init();
    
    World * world = getWorld();
    std::string pack_path = "../minecraft/";
    std::string id = "minecraft:redstone_torch[lit=true]";
    std::string out_path = "../blockCache/";

    

    convert(pack_path, id, out_path);

    

    // std::ifstream f("../c.0.0.nbt", std::ifstream::binary);
    
    // nbtpp::nbt n(f);
    
    // n.debug();

    
    
    return 0;
}
