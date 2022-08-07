#pragma once

#include "RoverScriptCompiler/token/token.h"

class CommentToken : public Token
{
public:
    CommentToken(const std::string& value) : value(value) {}

    std::string getName() override
    {
        return "comment";
    }

    TokenID getId() override
    {
        return TokenID::COMMENT;
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