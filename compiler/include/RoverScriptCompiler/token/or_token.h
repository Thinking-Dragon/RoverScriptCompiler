#pragma once

#include "RoverScriptCompiler/token/token.h"

class OrToken : public Token
{
public:
    std::string getName() override
    {
        return "or";
    }
    
    TokenID getId() override
    {
        return TokenID::OR;
    }
};