#pragma once

#include <memory>
#include "RoverScriptCompiler/ast/ast_node.h"

class AstAction : public AstNode
{
public:
    std::vector<std::shared_ptr<AstNode>> getChildren();

private:
    std::vector<std::shared_ptr<AstNode>> children;
};