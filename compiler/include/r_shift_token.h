#pragma once

#include "RoverScriptCompiler/token/token.h"

class RShiftToken : public Token
{
public:
    std::string getName() override
    {
        return "r_shift";
    }
    
    TokenID getId() override
    {
        return TokenID::R_SHIFT;
    }
};