#pragma once

#include "RoverScriptCompiler/token/token.h"

class LessToken : public Token
{
public:
    std::string getName() override
    {
        return "less";
    }
    
    TokenID getId() override
    {
        return TokenID::LESS;
    }
};