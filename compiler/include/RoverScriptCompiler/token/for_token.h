#pragma once

#include "RoverScriptCompiler/token/token.h"

class ForToken : public Token
{
public:
    std::string getName() override
    {
        return "for";
    }
    
    TokenID getId() override
    {
        return TokenID::FOR;
    }
};