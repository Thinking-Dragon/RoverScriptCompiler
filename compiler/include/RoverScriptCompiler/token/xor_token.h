#pragma once

#include "RoverScriptCompiler/token/token.h"

class XorToken : public Token
{
public:
    std::string getName() override
    {
        return "xor";
    }
    
    TokenID getId() override
    {
        return TokenID::XOR;
    }
};