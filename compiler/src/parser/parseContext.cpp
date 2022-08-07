#include "RoverScriptCompiler/parser/parseContext.h"

std::shared_ptr<Token> ParseContext::currentToken() const
{
    return tokens[cursor];
}

std::shared_ptr<Token> ParseContext::lookAhead(const unsigned int& offset) const
{
    return tokens[cursor + offset];
}

void ParseContext::gotoNextToken()
{
    ++cursor;
}

bool ParseContext::reachedEnd() const
{
    return cursor >= tokens.size();
}