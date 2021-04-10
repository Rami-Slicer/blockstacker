#include <archive.hpp>

namespace bio = boost::iostreams;

std::string Archive::compress(std::string & in) {

    

    std::stringstream decompressed(in);
    std::stringstream compressed;

    bio::filtering_streambuf<bio::input> out;
    out.push(bio::zlib_compressor());
    out.push(decompressed);
    bio::copy(out, compressed);

    return compressed.str();
}

std::string Archive::decompress(std::string & in) {

    std::stringstream compressed(in);
    std::stringstream decompressed;

    bio::filtering_streambuf<bio::input> out;
    out.push(bio::zlib_decompressor());
    out.push(compressed);
    bio::copy(out, decompressed);

    return decompressed.str();
}

std::string Gzip::compress(std::string & in) {

    std::stringstream decompressed(in);
    std::stringstream compressed;

    bio::filtering_streambuf<bio::input> out;
    out.push(bio::gzip_compressor());
    out.push(decompressed);
    bio::copy(out, compressed);

    return compressed.str();
}

std::string Gzip::decompress(std::string & in) {

    std::stringstream compressed(in);
    std::stringstream decompressed;

    bio::filtering_streambuf<bio::input> out;
    out.push(bio::gzip_decompressor());
    out.push(compressed);
    bio::copy(out, decompressed);

    return decompressed.str();
}
