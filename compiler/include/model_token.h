#pragma once

#include "RoverScriptCompiler/token/token.h"

class ModelToken : public Token
{
public:
    std::string getName() override
    {
        return "model";
    }
    
    TokenID getId() override
    {
        return TokenID::MODEL;
    }
};