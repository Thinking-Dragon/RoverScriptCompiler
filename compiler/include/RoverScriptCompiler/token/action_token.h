#pragma once

#include "RoverScriptCompiler/token/token.h"

class ActionToken : public Token
{
public:
    std::string getName() override
    {
        return "action";
    }
    
    TokenID getId() override
    {
        return TokenID::ACTION;
    }
};