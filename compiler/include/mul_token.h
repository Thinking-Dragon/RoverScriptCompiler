#pragma once

#include "RoverScriptCompiler/token/token.h"

class MulToken : public Token
{
public:
    std::string getName() override
    {
        return "mul";
    }
    
    TokenID getId() override
    {
        return TokenID::MUL;
    }
};