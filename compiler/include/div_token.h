#pragma once

#include "RoverScriptCompiler/token/token.h"

class DivToken : public Token
{
public:
    std::string getName() override
    {
        return "div";
    }
    
    TokenID getId() override
    {
        return TokenID::DIV;
    }
};