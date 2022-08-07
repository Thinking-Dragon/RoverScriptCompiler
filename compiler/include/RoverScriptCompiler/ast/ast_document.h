#pragma once

#include <vector>
#include <memory>
#include "RoverScriptCompiler/ast/ast_node.h"

class AstDocument : public AstNode
{
public:
    AstDocument(const std::vector<std::shared_ptr<AstNode>>& children) : children(children) {}

private:
    std::vector<std::shared_ptr<AstNode>> children;
};