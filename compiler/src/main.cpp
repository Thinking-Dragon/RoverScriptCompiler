#include <iostream>
#include <fstream>

#include <vector>
#include <memory>
#include <string>
#include "sstream"

#include "RoverScriptCompiler/token/tokens.h"
#include "RoverScriptCompiler/tokenizer/tokenizer.h"

#include "RoverScriptCompiler/ast/ast_nodes.h"
#include "RoverScriptCompiler/parser/parser.h"

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

    Tokenizer tokenizer;
    std::vector<std::shared_ptr<Token>> tokens = tokenizer.tokenize(sourceCode);

    Parser parser;
    std::shared_ptr<AstNode> ast = parser.parse(tokens);

    return 0;
}