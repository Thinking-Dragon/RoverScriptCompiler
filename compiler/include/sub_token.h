#pragma once

#include "RoverScriptCompiler/token/token.h"

class SubToken : public Token
{
public:
    std::string getName() override
    {
        return "sub";
    }
    
    TokenID getId() override
    {
        return TokenID::SUB;
    }
};