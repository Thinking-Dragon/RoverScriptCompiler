#pragma once

#include "RoverScriptCompiler/token/token.h"

class GreaterEQToken : public Token
{
public:
    std::string getName() override
    {
        return "greater_eq";
    }
    
    TokenID getId() override
    {
        return TokenID::GREATER_EQ;
    }
};