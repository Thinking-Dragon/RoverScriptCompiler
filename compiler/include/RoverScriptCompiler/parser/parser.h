#pragma once

#include <memory>
#include <vector>
#include <iostream>

#include "RoverScriptCompiler/parser/parseContext.h"
#include "RoverScriptCompiler/ast/ast_nodes.h"
#include "RoverScriptCompiler/token/token.h"
#include "RoverScriptCompiler/token/tokens.h"
#include "RoverScriptCompiler/token/token_id.h"

class Parser
{
public:
    std::shared_ptr<AstNode> parse(const std::vector<std::shared_ptr<Token>>& tokens);

private:
    std::shared_ptr<AstNode> walkDocument(ParseContext& ctx);

    std::shared_ptr<AstStrategy> walkStrategy(ParseContext& ctx);
    std::shared_ptr<AstAction> walkAction(ParseContext& ctx);
    std::shared_ptr<AstTrigger> walkTrigger(ParseContext& ctx);
    std::shared_ptr<AstModel> walkModel(ParseContext& ctx);
    std::shared_ptr<AstEnum> walkEnum(ParseContext& ctx);

    std::shared_ptr<AstScope> walkScope(ParseContext& ctx);
    std::shared_ptr<AstStrategyBody> walkStrategyBody(ParseContext& ctx);

    std::shared_ptr<AstStatement> walkStatement(ParseContext& ctx);

    bool isType(const std::shared_ptr<Token>& token) const;
    bool isStrategyBody(const std::shared_ptr<Token>& nextToken) const;

};