#include <iostream>
#include <fstream>
// #include <nbt.hpp>
// #include <nbt++/io/stream_reader.h>
#include <string>
#include <minecraft-file.hpp>
#include <memory>
// #include <nbtpp/nbt.hpp>

int main(int, char**) {
    namespace mc = mcfile;

    std::shared_ptr<mc::Region> region = mc::Region::MakeRegion("../r.0.0.mca");
    std::cout << region->chunkExists(1, 2) << std::endl;
    std::shared_ptr<mc::Chunk> chunk = region->chunkAt(1, 2);

    // const mc::Block glowstone = new mc::Block("glowstone");
    const std::shared_ptr<mc::Block const> p(new mc::Block("glowstone"));

    chunk->setBlockAt(1,255,1, p);

    // std::ifstream f("../c.0.0.nbt", std::ifstream::binary);
    
    // nbtpp::nbt n(f);
    
    // n.debug();
    
    return 0;
}
