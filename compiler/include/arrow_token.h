#pragma once

#include "RoverScriptCompiler/token/token.h"

class ArrowToken : public Token
{
public:
    std::string getName() override
    {
        return "arrow";
    }
    
    TokenID getId() override
    {
        return TokenID::ARROW;
    }
};