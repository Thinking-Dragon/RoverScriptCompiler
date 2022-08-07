#pragma once

#include <string>
#include "RoverScriptCompiler/ast/ast_node.h"

class AstSymbol : public AstNode
{
public:
    AstSymbol(const std::string& content) : content(content) {}

private:
    std::string content;
};