#pragma once

#include <vector>
#include <memory>

#include "RoverScriptCompiler/ast/ast_node.h"
#include "RoverScriptCompiler/ast/ast_statement.h"

class AstScope : public AstNode
{
public:
    AstScope(const std::vector<std::shared_ptr<AstStatement>>& statements) : statements(statements) {}

private:
    std::vector<std::shared_ptr<AstStatement>> statements;

};