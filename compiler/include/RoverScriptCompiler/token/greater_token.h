#pragma once

#include "RoverScriptCompiler/token/token.h"

class GreaterToken : public Token
{
public:
    std::string getName() override
    {
        return "greater";
    }
    
    TokenID getId() override
    {
        return TokenID::GREATER;
    }
};