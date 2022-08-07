#pragma once

#include "RoverScriptCompiler/token/token.h"

class CommaToken : public Token
{
public:
    std::string getName() override
    {
        return "comma";
    }
    
    TokenID getId() override
    {
        return TokenID::COMMA;
    }
};