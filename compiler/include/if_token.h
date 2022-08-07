#pragma once

#include "RoverScriptCompiler/token/token.h"

class IfToken : public Token
{
public:
    std::string getName() override
    {
        return "if";
    }
    
    TokenID getId() override
    {
        return TokenID::IF;
    }
};