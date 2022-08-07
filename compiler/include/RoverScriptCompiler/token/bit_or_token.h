#pragma once

#include "RoverScriptCompiler/token/token.h"

class BitOrToken : public Token
{
public:
    std::string getName() override
    {
        return "bit_or";
    }
    
    TokenID getId() override
    {
        return TokenID::BIT_OR;
    }
};