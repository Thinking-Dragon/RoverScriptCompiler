#pragma once

#include "RoverScriptCompiler/token/token.h"

class RBraceToken : public Token
{
public:
    std::string getName() override
    {
        return "r_brace";
    }
    
    TokenID getId() override
    {
        return TokenID::R_BRACE;
    }
};