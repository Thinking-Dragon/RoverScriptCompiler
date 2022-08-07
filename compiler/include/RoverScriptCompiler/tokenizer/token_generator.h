#pragma once

#include <string>
#include <memory>
#include "RoverScriptCompiler/token/token.h"

struct TokenGenerator
{
    std::string token;
    std::function<std::shared_ptr<Token>()> generate;
};

static std::vector<TokenGenerator> tokenGenerators = {
    { "actionStack", [](){ return std::make_shared<ActionStackToken>(); } },
    { "strategy", [](){ return std::make_shared<StrategyToken>(); } },
    { "action", [](){ return std::make_shared<ActionToken>(); } },
    { "triggers", [](){ return std::make_shared<TriggersToken>(); } },
    { "trigger", [](){ return std::make_shared<TriggerToken>(); } },
    { "model", [](){ return std::make_shared<ModelToken>(); } },
    { "enum", [](){ return std::make_shared<EnumToken>(); } },
    { "start", [](){ return std::make_shared<StartToken>(); } },
    { "loop", [](){ return std::make_shared<LoopToken>(); } },
    { "data", [](){ return std::make_shared<DataToken>(); } },
    { "int", [](){ return std::make_shared<TIntToken>(); } },
    { "long", [](){ return std::make_shared<TLongToken>(); } },
    { "float", [](){ return std::make_shared<TFloatToken>(); } },
    { "double", [](){ return std::make_shared<TDoubleToken>(); } },
    { "bool", [](){ return std::make_shared<TBoolToken>(); } },
    { "string", [](){ return std::make_shared<TStringToken>(); } },
    { "timer", [](){ return std::make_shared<TTimerToken>(); } },
    { "if", [](){ return std::make_shared<IfToken>(); } },
    { "else", [](){ return std::make_shared<ElseToken>(); } },
    { "do", [](){ return std::make_shared<DoToken>(); } },
    { "while", [](){ return std::make_shared<WhileToken>(); } },
    { "for", [](){ return std::make_shared<ForToken>(); } },
    { "==", [](){ return std::make_shared<EqualsToken>(); } },
    { ">", [](){ return std::make_shared<GreaterToken>(); } },
    { "<", [](){ return std::make_shared<LessToken>(); } },
    { ">=", [](){ return std::make_shared<GreaterEQToken>(); } },
    { "<=", [](){ return std::make_shared<LessEQToken>(); } },
    { "=", [](){ return std::make_shared<AssignToken>(); } },
    { "->", [](){ return std::make_shared<ArrowToken>(); } },
    { "&&", [](){ return std::make_shared<AndToken>(); } },
    { "||", [](){ return std::make_shared<OrToken>(); } },
    { "^", [](){ return std::make_shared<XorToken>(); } },
    { "!", [](){ return std::make_shared<NotToken>(); } },
    { "<<", [](){ return std::make_shared<LShiftToken>(); } },
    { ">>", [](){ return std::make_shared<RShiftToken>(); } },
    { "&", [](){ return std::make_shared<BitAndToken>(); } },
    { "|", [](){ return std::make_shared<BitOrToken>(); } },
    { "+", [](){ return std::make_shared<AddToken>(); } },
    { "-", [](){ return std::make_shared<SubToken>(); } },
    { "*", [](){ return std::make_shared<MulToken>(); } },
    { "/", [](){ return std::make_shared<DivToken>(); } },
    { "%", [](){ return std::make_shared<ModToken>(); } },
    { ".", [](){ return std::make_shared<DotToken>(); } },
    { ",", [](){ return std::make_shared<CommaToken>(); } },
    { "(", [](){ return std::make_shared<LParenToken>(); } },
    { ")", [](){ return std::make_shared<RParenToken>(); } },
    { "{", [](){ return std::make_shared<LBraceToken>(); } },
    { "}", [](){ return std::make_shared<RBraceToken>(); } },
    { "|", [](){ return std::make_shared<BitOrToken>(); } },
};