#pragma once

#include "RoverScriptCompiler/token/token.h"

class EnumToken : public Token
{
public:
    std::string getName() override
    {
        return "enum";
    }
    
    TokenID getId() override
    {
        return TokenID::ENUM;
    }
};