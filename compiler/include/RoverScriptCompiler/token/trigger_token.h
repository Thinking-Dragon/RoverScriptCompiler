#pragma once

#include "RoverScriptCompiler/token/token.h"

class TriggerToken : public Token
{
public:
    std::string getName() override
    {
        return "trigger";
    }
    
    TokenID getId() override
    {
        return TokenID::TRIGGER;
    }
};