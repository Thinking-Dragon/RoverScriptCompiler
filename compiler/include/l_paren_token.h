#pragma once

#include "RoverScriptCompiler/token/token.h"

class LParenToken : public Token
{
public:
    std::string getName() override
    {
        return "l_paren";
    }
    
    TokenID getId() override
    {
        return TokenID::L_PAREN;
    }
};