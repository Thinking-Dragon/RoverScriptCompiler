#pragma once

#include "RoverScriptCompiler/token/token.h"

class TStringToken : public Token
{
public:
    std::string getName() override
    {
        return "t_string";
    }
    
    TokenID getId() override
    {
        return TokenID::T_STRING;
    }
};