#pragma once

#include "RoverScriptCompiler/token/token.h"

class LNumberToken : public Token
{
public:
    LNumberToken(const std::string& value) : value(value) {}

    std::string getName() override
    {
        return "l_number";
    }
    
    TokenID getId() override
    {
        return TokenID::L_NUMBER;
    }

    std::string getValue()
    {
        return value;
    }

    std::string toString() override
    {
        return getName() + ": " + getValue();
    }

private:
    std::string value;
};