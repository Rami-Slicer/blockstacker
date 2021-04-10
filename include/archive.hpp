#pragma once

#include <string>
#include <sstream>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/zlib.hpp>
#include <boost/iostreams/filter/gzip.hpp>


class Archive {
    public:
        static std::string compress(std::string & in);
        static std::string decompress(std::string & in);
};

class Gzip {
    public:
        static std::string compress(std::string & in);
        static std::string decompress(std::string & in);
};