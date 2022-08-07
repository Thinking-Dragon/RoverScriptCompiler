#pragma once

#include <string>
#include "RoverScriptCompiler/token/token_id.h"

class Token {
public:
    virtual std::string getName() = 0;
    virtual TokenID getId() = 0;
    virtual std::string toString() { return getName(); }
};