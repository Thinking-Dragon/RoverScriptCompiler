#pragma once

#include "RoverScriptCompiler/token/token.h"

class TLongToken : public Token
{
public:
    std::string getName() override
    {
        return "t_long";
    }
    
    TokenID getId() override
    {
        return TokenID::T_LONG;
    }
};