#pragma once

#include "RoverScriptCompiler/token/token.h"

class AndToken : public Token
{
public:
    std::string getName() override
    {
        return "and";
    }

    
    TokenID getId() override
    {
        return TokenID::AND;
    }
};