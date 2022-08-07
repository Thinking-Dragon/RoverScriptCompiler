#pragma once

#include "RoverScriptCompiler/token/token.h"

class DoToken : public Token
{
public:
    std::string getName() override
    {
        return "do";
    }
    
    TokenID getId() override
    {
        return TokenID::DO;
    }
};