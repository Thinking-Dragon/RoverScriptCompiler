#pragma once

#include <vector>
#include <memory>
#include "RoverScriptCompiler/token/token.h"

class ParseContext
{
public:
    ParseContext(const std::vector<std::shared_ptr<Token>>& tokens) : cursor(0), tokens(tokens) {}

    std::shared_ptr<Token> currentToken() const;
    std::shared_ptr<Token> lookAhead(const unsigned int& offset) const;

    void gotoNextToken();

    bool reachedEnd() const;

private:
    unsigned int cursor;
    std::vector<std::shared_ptr<Token>> tokens;

};