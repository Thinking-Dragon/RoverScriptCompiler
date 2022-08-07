#pragma once

#include "RoverScriptCompiler/token/token.h"

class EqualsToken : public Token
{
public:
    std::string getName() override
    {
        return "equals";
    }
    
    TokenID getId() override
    {
        return TokenID::EQUALS;
    }
};