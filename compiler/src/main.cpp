#include <iostream>
#include <fstream>

#include <vector>
#include <memory>
#include <string>
#include "sstream"

std::string loadFile(const std::string& fileName) {
    std::ifstream stream(fileName);
    std::stringstream buffer;
    buffer << stream.rdbuf();
    return buffer.str();
}

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cerr << "Wrong number of arguments, expected usage: rsc <filename>" << std::endl;
        exit(1);
    }

    std::string fileName = *(argv + 1);
    std::string sourceCode = loadFile(fileName);

    // TODO: tokenize, parse and output compiled code

    return 0;
}