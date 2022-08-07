#pragma once

#include <memory>
#include <vector>

#include "RoverScriptCompiler/ast/ast_node.h"
#include "RoverScriptCompiler/ast/ast_var_declaration.h"

class AstStrategy : public AstNode
{
public:
    AstStrategy(
        const std::string& name,
        const std::vector<std::shared_ptr<AstVarDeclaration>>& parameters,
        const std::shared_ptr<AstNode>& content
    ) : name(name), parameters(parameters), content(content) {}
    std::vector<std::shared_ptr<AstVarDeclaration>> getParameters();
    std::shared_ptr<AstNode> getContent();

private:
    std::string name;
    std::vector<std::shared_ptr<AstVarDeclaration>> parameters;
    std::shared_ptr<AstNode> content;
};