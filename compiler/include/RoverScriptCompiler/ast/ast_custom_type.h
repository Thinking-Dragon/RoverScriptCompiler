#pragma once

#include <string>
#include "RoverScriptCompiler/ast/ast_node.h"

class AstCustomType : public AstNode
{
public:
    AstCustomType(const std::string& name) : name(name) {}

private:
    std::string name;

};