#pragma once

#include "RoverScriptCompiler/token/token.h"

class TIntToken : public Token
{
public:
    std::string getName() override
    {
        return "t_int";
    }
    
    TokenID getId() override
    {
        return TokenID::T_INTEGER;
    }
};