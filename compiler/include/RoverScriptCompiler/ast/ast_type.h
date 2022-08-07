#pragma once

#include "RoverScriptCompiler/ast/ast_node.h"

enum VariableType
{
    INTEGER,
    LONG,
    FLOAT,
    DOUBLE,
    BOOLEAN,
    TIMER,
    STRING,
};

class AstType : public AstNode
{
public:
    AstType(const VariableType& type) : type(type) {}

private:
    VariableType type;

};