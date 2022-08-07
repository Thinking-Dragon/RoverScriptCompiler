#pragma once

#include <iostream>

#include <functional>
#include <vector>
#include <memory>
#include <string>

#include "RoverScriptCompiler/token/tokens.h"
#include "RoverScriptCompiler/tokenizer/token_generator.h"

class Tokenizer
{
public:
    std::vector<std::shared_ptr<Token>> tokenize(const std::string& sourceCode);

private:
    bool checkForComment(const std::string& sourceCode, int& index, std::vector<std::shared_ptr<Token>>& tokens);
    bool checkForFixedTokens(const std::string& sourceCode, int& index, std::vector<std::shared_ptr<Token>>& tokens);
    bool checkForNumberLitteral(const std::string& sourceCode, int& index, std::vector<std::shared_ptr<Token>>& tokens);
    bool checkForStringLitteral(const std::string& sourceCode, int& index, std::vector<std::shared_ptr<Token>>& tokens);
    bool checkForSymbolToken(const std::string& sourceCode, int& index, std::vector<std::shared_ptr<Token>>& tokens);

    bool fixedTokenMatch(const std::string& sourceCode, const std::string& tokenValue, const unsigned int& index);
    bool numberTokenMatch(const std::string& sourceCode, const unsigned int& index);
    bool symbolTokenMatch(const std::string& sourceCode, const unsigned int& index);

    std::string getNumberToken(const std::string& sourceCode, const unsigned int& index);
    std::string getStringToken(const std::string& sourceCode, const unsigned int& index);
    std::string getSymbolToken(const std::string& sourceCode, const unsigned int& index);
    std::string getCommentToken(const std::string& sourceCode, const unsigned int& index);
};