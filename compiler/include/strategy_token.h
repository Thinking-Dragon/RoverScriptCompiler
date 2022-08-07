#pragma once

#include "RoverScriptCompiler/token/token.h"

class StrategyToken : public Token
{
public:
    std::string getName() override
    {
        return "strategy";
    }
    
    TokenID getId() override
    {
        return TokenID::STRATEGY;
    }
};