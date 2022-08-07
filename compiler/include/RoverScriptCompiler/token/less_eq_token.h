#pragma once

#include "RoverScriptCompiler/token/token.h"

class LessEQToken : public Token
{
public:
    std::string getName() override
    {
        return "less_eq";
    }
    
    TokenID getId() override
    {
        return TokenID::LESS_EQ;
    }
};