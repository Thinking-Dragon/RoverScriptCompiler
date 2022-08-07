#pragma once

#include "RoverScriptCompiler/token/token.h"

class LStringToken : public Token
{
public:
    LStringToken(const std::string& value) : value(value) {}

    std::string getName() override
    {
        return "l_string";
    }
    
    TokenID getId() override
    {
        return TokenID::L_STRING;
    }

    std::string getValue()
    {
        return value;
    }

    std::string toString() override
    {
        return getName() + ": \"" + getValue() + "\"";
    }

private:
    std::string value;
};