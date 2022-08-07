#pragma once

#include "RoverScriptCompiler/token/token.h"

class WhileToken : public Token
{
public:
    std::string getName() override
    {
        return "while";
    }
    
    TokenID getId() override
    {
        return TokenID::WHILE;
    }
};