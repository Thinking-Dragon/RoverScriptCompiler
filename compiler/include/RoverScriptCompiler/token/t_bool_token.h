#pragma once

#include "RoverScriptCompiler/token/token.h"

class TBoolToken : public Token
{
public:
    std::string getName() override
    {
        return "t_bool";
    }
    
    TokenID getId() override
    {
        return TokenID::T_BOOLEAN;
    }
};