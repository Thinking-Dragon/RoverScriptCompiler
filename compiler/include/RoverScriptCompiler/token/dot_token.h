#pragma once

#include "RoverScriptCompiler/token/token.h"

class DotToken : public Token
{
public:
    std::string getName() override
    {
        return "dot";
    }
    
    TokenID getId() override
    {
        return TokenID::DOT;
    }
};