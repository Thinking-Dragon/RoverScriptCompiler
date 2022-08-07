#pragma once

#include "RoverScriptCompiler/token/token.h"

class ActionStackToken : public Token
{
public:
    std::string getName() override
    {
        return "action_stack";
    }

    TokenID getId() override
    {
        return TokenID::ACTION_STACK;
    }
};