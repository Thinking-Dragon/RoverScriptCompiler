#pragma once

#include "RoverScriptCompiler/token/token.h"

class LShiftToken : public Token
{
public:
    std::string getName() override
    {
        return "l_shift";
    }
    
    TokenID getId() override
    {
        return TokenID::L_SHIFT;
    }
};