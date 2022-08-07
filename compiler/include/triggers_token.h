#pragma once

#include "RoverScriptCompiler/token/token.h"

class TriggersToken : public Token
{
public:
    std::string getName() override
    {
        return "triggers";
    }
    
    TokenID getId() override
    {
        return TokenID::TRIGGERS;
    }
};