#pragma once

#include "RoverScriptCompiler/token/token.h"

class ModToken : public Token
{
public:
    std::string getName() override
    {
        return "mod";
    }
    
    TokenID getId() override
    {
        return TokenID::MOD;
    }
};