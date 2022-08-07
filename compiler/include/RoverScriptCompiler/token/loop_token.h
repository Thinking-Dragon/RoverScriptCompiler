#pragma once

#include "RoverScriptCompiler/token/token.h"

class LoopToken : public Token
{
public:
    std::string getName() override
    {
        return "loop";
    }
    
    TokenID getId() override
    {
        return TokenID::LOOP;
    }
};