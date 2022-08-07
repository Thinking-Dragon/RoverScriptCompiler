#pragma once

#include "RoverScriptCompiler/token/token.h"

class AddToken : public Token
{
public:
    std::string getName() override
    {
        return "add";
    }
    
    TokenID getId() override
    {
        return TokenID::ADD;
    }
};