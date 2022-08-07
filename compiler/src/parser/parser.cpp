#include "RoverScriptCompiler/parser/parser.h"

std::shared_ptr<AstNode> Parser::parse(const std::vector<std::shared_ptr<Token>>& tokens)
{
    ParseContext ctx(tokens);
    return walkDocument(ctx);
}

std::shared_ptr<AstNode> Parser::walkDocument(ParseContext& ctx)
{
    std::cout << "Walking document" << std::endl;

    std::vector<std::shared_ptr<AstNode>> children;

    while(!ctx.reachedEnd())
    {
        switch (ctx.currentToken()->getId())
        {
        case TokenID::STRATEGY:
            children.push_back(walkStrategy(ctx));
            break;
        case TokenID::ACTION:
            children.push_back(walkAction(ctx));
            break;
        case TokenID::TRIGGER:
            children.push_back(walkTrigger(ctx));
            break;
        case TokenID::MODEL:
            children.push_back(walkModel(ctx));
            break;
        case TokenID::ENUM:
            children.push_back(walkEnum(ctx));
            break;
        case TokenID::COMMENT:
            ctx.gotoNextToken();
            break;
        default:
            //std::cout << "Unexpected token: " << ctx.currentToken()->getName() << std::endl;
            break;
        }
    }

    return std::make_shared<AstDocument>(children);
}

std::shared_ptr<AstStrategy> Parser::walkStrategy(ParseContext& ctx)
{
    std::cout << "Walking strategy" << std::endl;

    if(ctx.currentToken()->getId() != TokenID::STRATEGY)
        std::cerr << "Expected strategy, got: " << ctx.currentToken()->getName() << std::endl;
    ctx.gotoNextToken();

    if(ctx.currentToken()->getId() != TokenID::SYMBOL)
        std::cerr << "Expected symbol, got: " << ctx.currentToken()->getName() << std::endl;

    std::string name = std::dynamic_pointer_cast<SymbolToken>(ctx.currentToken())->getValue();
    ctx.gotoNextToken();

    std::vector<std::shared_ptr<AstVarDeclaration>> parameters;
    if(ctx.currentToken()->getId() == TokenID::L_PAREN)
    {
        while(ctx.currentToken()->getId() != TokenID::R_PAREN)
        {
            if(isType(ctx.currentToken())){
                VariableType variableType;
                switch (ctx.currentToken()->getId())
                {
                case TokenID::T_INTEGER:
                    variableType = VariableType::INTEGER;
                    break;
                case TokenID::T_LONG:
                    variableType = VariableType::LONG;
                    break;
                case TokenID::T_FLOAT:
                    variableType = VariableType::FLOAT;
                    break;
                case TokenID::T_DOUBLE:
                    variableType = VariableType::DOUBLE;
                    break;
                case TokenID::T_BOOLEAN:
                    variableType = VariableType::BOOLEAN;
                    break;
                case TokenID::T_STRING:
                    variableType = VariableType::STRING;
                    break;
                case TokenID::T_TIMER:
                    variableType = VariableType::TIMER;
                    break;
                }
                std::shared_ptr<AstType> type = std::make_shared<AstType>(variableType);
                ctx.gotoNextToken();

                if(ctx.currentToken()->getId() != TokenID::SYMBOL)
                    std::cerr << "Expected parameter name, got: " << ctx.currentToken()->getName() << std::endl;

                std::string variableName = std::dynamic_pointer_cast<SymbolToken>(ctx.currentToken())->getValue();
                std::shared_ptr<AstSymbol> name = std::make_shared<AstSymbol>(variableName);
                ctx.gotoNextToken();

                parameters.push_back(std::make_shared<AstVarDeclaration>(type, name));
            }
            else if(ctx.currentToken()->getId() == TokenID::SYMBOL)
            {
                std::string typeName = std::dynamic_pointer_cast<SymbolToken>(ctx.currentToken())->getValue();
                std::shared_ptr<AstCustomType> type = std::make_shared<AstCustomType>(typeName);
                ctx.gotoNextToken();

                if(ctx.currentToken()->getId() != TokenID::SYMBOL)
                    std::cerr << "Expected parameter name, got: " << ctx.currentToken()->getName() << std::endl;

                std::string variableName = std::dynamic_pointer_cast<SymbolToken>(ctx.currentToken())->getValue();
                std::shared_ptr<AstSymbol> name = std::make_shared<AstSymbol>(variableName);
                ctx.gotoNextToken();

                parameters.push_back(std::make_shared<AstVarDeclaration>(type, name));
            }
            else
            {
                ctx.gotoNextToken();
                continue;
            }
        }
    }

    std::shared_ptr<AstNode> content = isStrategyBody(ctx.lookAhead(1)) ?
              std::dynamic_pointer_cast<AstNode>(walkStrategyBody(ctx)) :
              std::dynamic_pointer_cast<AstNode>(walkScope(ctx));

    return std::make_shared<AstStrategy>(name, parameters, content);
}

std::shared_ptr<AstAction> Parser::walkAction(ParseContext& ctx)
{
    std::cout << "Walking action" << std::endl;
}

std::shared_ptr<AstTrigger> Parser::walkTrigger(ParseContext& ctx)
{
    std::cout << "Walking trigger" << std::endl;
}

std::shared_ptr<AstModel> Parser::walkModel(ParseContext& ctx)
{
    std::cout << "Walking model" << std::endl;
}

std::shared_ptr<AstEnum> Parser::walkEnum(ParseContext& ctx)
{
    if(ctx.currentToken()->getId() != TokenID::ENUM)
        std::cerr << "Expected enum, got: " << ctx.currentToken()->getName() << std::endl;
    ctx.gotoNextToken();
    
    if(ctx.currentToken()->getId() != TokenID::SYMBOL)
        std::cerr << "Expected symbol, got: " << ctx.currentToken()->getName() << std::endl;

    std::string name = std::dynamic_pointer_cast<SymbolToken>(ctx.currentToken())->getValue();
    ctx.gotoNextToken();

    if(ctx.currentToken()->getId() != TokenID::L_BRACE)
        std::cerr << "Expected {, got: " << ctx.currentToken()->getName() << std::endl;
    ctx.gotoNextToken();

    std::vector<std::string> options;
    while(ctx.currentToken()->getId() != TokenID::R_BRACE)
    {
        if(ctx.currentToken()->getId() == TokenID::SYMBOL)
            options.push_back(std::dynamic_pointer_cast<SymbolToken>(ctx.currentToken())->getValue());
        ctx.gotoNextToken();
    }
    ctx.gotoNextToken();

    return std::make_shared<AstEnum>(name, options);
}

std::shared_ptr<AstScope> Parser::walkScope(ParseContext& ctx)
{
    std::cout << "Walking scope" << std::endl;

    if(ctx.currentToken()->getId() != TokenID::L_BRACE)
        std::cerr << "Expected {, got: " << ctx.currentToken() << std::endl;
    ctx.gotoNextToken();

    std::vector<std::shared_ptr<AstStatement>> statements;
    while(ctx.currentToken()->getId() != TokenID::R_BRACE)
    {
        statements.push_back(walkStatement(ctx));
    }
    ctx.gotoNextToken();

    return std::make_shared<AstScope>(statements);
}

std::shared_ptr<AstStrategyBody> Parser::walkStrategyBody(ParseContext& ctx)
{
    std::cout << "Walking strategy body" << std::endl;

    if(ctx.currentToken()->getId() != TokenID::L_BRACE)
        std::cerr << "Expected {, got: " << ctx.currentToken() << std::endl;
    ctx.gotoNextToken();
}

std::shared_ptr<AstStatement> Parser::walkStatement(ParseContext& ctx)
{
    std::cout << "Walking statement" << std::endl;
    ctx.gotoNextToken();
    return std::make_shared<AstStatement>();
}

bool Parser::isType(const std::shared_ptr<Token>& token) const
{
    switch (token->getId())
    {
    case TokenID::T_INTEGER:
    case TokenID::T_LONG:
    case TokenID::T_FLOAT:
    case TokenID::T_DOUBLE:
    case TokenID::T_BOOLEAN:
    case TokenID::T_STRING:
    case TokenID::T_TIMER:
        return true;
    default:
        return false;
    }
}

bool Parser::isStrategyBody(const std::shared_ptr<Token>& nextToken) const
{
    switch (nextToken->getId())
    {
    case TokenID::DATA:
    case TokenID::TRIGGERS:
    case TokenID::LOOP:
    case TokenID::START:
        return true;
    default:
        return false;
    }
}