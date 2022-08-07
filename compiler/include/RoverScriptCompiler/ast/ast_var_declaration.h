#pragma once

#include <memory>

#include "RoverScriptCompiler/ast/ast_node.h"
#include "RoverScriptCompiler/ast/ast_symbol.h"

class AstVarDeclaration : public AstNode
{
public:
    AstVarDeclaration(const std::shared_ptr<AstNode>& type, const std::shared_ptr<AstSymbol>& name)
        : type(type), name(name)
    {}

private:
    std::shared_ptr<AstNode> type;
    std::shared_ptr<AstSymbol> name;
};