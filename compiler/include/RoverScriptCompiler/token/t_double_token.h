#pragma once

#include "RoverScriptCompiler/token/token.h"

class TDoubleToken : public Token
{
public:
    std::string getName() override
    {
        return "t_double";
    }
    
    TokenID getId() override
    {
        return TokenID::T_DOUBLE;
    }
};