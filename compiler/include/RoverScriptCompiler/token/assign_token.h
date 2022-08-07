#pragma once

#include "RoverScriptCompiler/token/token.h"

class AssignToken : public Token
{
public:
    std::string getName() override
    {
        return "assign";
    }
    
    TokenID getId() override
    {
        return TokenID::ASSIGN;
    }
};