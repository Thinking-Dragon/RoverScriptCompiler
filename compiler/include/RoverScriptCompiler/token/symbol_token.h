#pragma once

#include "RoverScriptCompiler/token/token.h"

class SymbolToken : public Token
{
public:
    SymbolToken(const std::string& value) : value(value) {}

    std::string getName() override
    {
        return "symbol";
    }
    
    TokenID getId() override
    {
        return TokenID::SYMBOL;
    }

    std::string getValue()
    {
        return value;
    }

    std::string toString() override
    {
        return getName() + ": " + getValue();
    }

private:
    std::string value;
};