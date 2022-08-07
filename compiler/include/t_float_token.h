#pragma once

#include "RoverScriptCompiler/token/token.h"

class TFloatToken : public Token
{
public:
    std::string getName() override
    {
        return "t_float";
    }
    
    TokenID getId() override
    {
        return TokenID::T_FLOAT;
    }
};