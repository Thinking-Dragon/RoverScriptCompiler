#pragma once

#include "RoverScriptCompiler/token/token.h"

class ElseToken : public Token
{
public:
    std::string getName() override
    {
        return "else";
    }
    
    TokenID getId() override
    {
        return TokenID::ELSE;
    }
};