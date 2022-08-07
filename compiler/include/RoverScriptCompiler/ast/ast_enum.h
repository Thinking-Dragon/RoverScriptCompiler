#pragma once

#include <string>
#include <vector>

#include "RoverScriptCompiler/ast/ast_node.h"

class AstEnum : public AstNode
{
public:
    AstEnum(const std::string& name, const std::vector<std::string>& options)
        : name(name), options(options)
    {}

private:
    std::string name;
    std::vector<std::string> options;
};