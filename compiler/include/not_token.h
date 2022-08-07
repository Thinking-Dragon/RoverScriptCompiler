#pragma once

#include "RoverScriptCompiler/token/token.h"

class NotToken : public Token
{
public:
    std::string getName() override
    {
        return "not";
    }
    
    TokenID getId() override
    {
        return TokenID::NOT;
    }
};