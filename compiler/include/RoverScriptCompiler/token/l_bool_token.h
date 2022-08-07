#pragma once

#include "RoverScriptCompiler/token/token.h"

class LBoolToken : public Token
{
public:
    LBoolToken(const bool& value) : value(value) {}

    std::string getName() override
    {
        return "l_bool";
    }
    
    TokenID getId() override
    {
        return TokenID::L_BOOL;
    }

    bool getValue()
    {
        return value;
    }

    std::string toString() override
    {
        return getName() + ": " + (getValue() ? "true" : "false");
    }

private:
    bool value;
};