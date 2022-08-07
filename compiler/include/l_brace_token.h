#pragma once

#include "RoverScriptCompiler/token/token.h"

class LBraceToken : public Token
{
public:
    std::string getName() override
    {
        return "l_brace";
    }
    
    TokenID getId() override
    {
        return TokenID::L_BRACE;
    }
};