#pragma once

#include "RoverScriptCompiler/token/token.h"

class RParenToken : public Token
{
public:
    std::string getName() override
    {
        return "r_paren";
    }
    
    TokenID getId() override
    {
        return TokenID::R_PAREN;
    }
};