#pragma once

#include "RoverScriptCompiler/token/token.h"

class BitAndToken : public Token
{
public:
    std::string getName() override
    {
        return "bit_and";
    }
    
    TokenID getId() override
    {
        return TokenID::BIT_AND;
    }
};