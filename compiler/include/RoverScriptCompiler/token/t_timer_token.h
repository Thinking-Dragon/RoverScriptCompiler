#pragma once

#include "RoverScriptCompiler/token/token.h"

class TTimerToken : public Token
{
public:
    std::string getName() override
    {
        return "t_timer";
    }
    
    TokenID getId() override
    {
        return TokenID::T_TIMER;
    }
};