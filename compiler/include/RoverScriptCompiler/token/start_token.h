#pragma once

#include "RoverScriptCompiler/token/token.h"

class StartToken : public Token
{
public:
    std::string getName() override
    {
        return "start";
    }
    
    TokenID getId() override
    {
        return TokenID::START;
    }
};