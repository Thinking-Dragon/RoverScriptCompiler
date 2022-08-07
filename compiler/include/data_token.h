#pragma once

#include "RoverScriptCompiler/token/token.h"

class DataToken : public Token
{
public:
    std::string getName() override
    {
        return "data";
    }
    
    TokenID getId() override
    {
        return TokenID::DATA;
    }
};