#include "RoverScriptCompiler/tokenizer/tokenizer.h"

std::vector<std::shared_ptr<Token>> Tokenizer::tokenize(const std::string& sourceCode)
{
    std::vector<std::shared_ptr<Token>> tokens;

    for(int index = 0; index < sourceCode.size(); ++index)
    {
        if(checkForComment(sourceCode, index, tokens)) continue;
        if(checkForFixedTokens(sourceCode, index, tokens)) continue;
        if(checkForNumberLitteral(sourceCode, index, tokens)) continue;
        if(checkForStringLitteral(sourceCode, index, tokens)) continue;
        if(checkForSymbolToken(sourceCode, index, tokens)) continue;
    }

    return tokens;
}

bool Tokenizer::checkForComment(const std::string& sourceCode, int& index, std::vector<std::shared_ptr<Token>>& tokens)
{
    bool foundToken = fixedTokenMatch(sourceCode, "//", index);

    if(foundToken)
    {
        std::string comment = getCommentToken(sourceCode, index);
        tokens.push_back(std::make_shared<CommentToken>(comment));
        index += comment.length() + 1;
    }
    
    return foundToken;
}

bool Tokenizer::checkForFixedTokens(const std::string& sourceCode, int& index, std::vector<std::shared_ptr<Token>>& tokens)
{
    bool fixedTokenDetected = false;
    for(auto tokenGenerator : tokenGenerators)
    {
        if(fixedTokenMatch(sourceCode, tokenGenerator.token, index))
        {
            tokens.push_back(tokenGenerator.generate());
            index += tokenGenerator.token.length() - 1;

            fixedTokenDetected = true;
            break;
        }
    }
    return fixedTokenDetected;
}

bool Tokenizer::checkForNumberLitteral(const std::string& sourceCode, int& index, std::vector<std::shared_ptr<Token>>& tokens)
{
    bool foundToken = numberTokenMatch(sourceCode, index);

    if(foundToken)
    {
        std::string number = getNumberToken(sourceCode, index);
        tokens.push_back(std::make_shared<LNumberToken>(number));
        index += number.length() - 1;
    }

    return foundToken;
}

bool Tokenizer::checkForStringLitteral(const std::string& sourceCode, int& index, std::vector<std::shared_ptr<Token>>& tokens)
{
    bool foundToken = fixedTokenMatch(sourceCode, "\"", index);

    if(foundToken)
    {
        std::string string = getStringToken(sourceCode, index);
        tokens.push_back(std::make_shared<LStringToken>(string));
        index += string.length() + 1;
    }

    return foundToken;
}

bool Tokenizer::checkForSymbolToken(const std::string& sourceCode, int& index, std::vector<std::shared_ptr<Token>>& tokens)
{
    bool foundToken = symbolTokenMatch(sourceCode, index);
    
    if(foundToken)
    {
        std::string symbol = getSymbolToken(sourceCode, index);
        tokens.push_back(std::make_shared<SymbolToken>(symbol));
        index += symbol.length() - 1;
    }

    return foundToken;
}

bool Tokenizer::fixedTokenMatch(const std::string& sourceCode, const std::string& tokenValue, const unsigned int& index)
{
    const unsigned int tokenLength = tokenValue.size();
    const bool isMatch = sourceCode.compare(index, tokenLength, tokenValue) == 0;

    return isMatch;
}

bool Tokenizer::numberTokenMatch(const std::string& sourceCode, const unsigned int& index)
{
    return (sourceCode[index] >= '0' && sourceCode[index] <= '9') || sourceCode[index] == '.';
}

bool Tokenizer::symbolTokenMatch(const std::string& sourceCode, const unsigned int& index)
{
    return (sourceCode[index] >= 'a' && sourceCode[index] <= 'z') ||
           (sourceCode[index] >= 'A' && sourceCode[index] <= 'Z') ||
           (sourceCode[index] >= '0' && sourceCode[index] <= '9') ||
            sourceCode[index] == '_';
}

std::string Tokenizer::getNumberToken(const std::string& sourceCode, const unsigned int& index)
{
    unsigned int cursor = index;

    std::string digits;
    while(numberTokenMatch(sourceCode, cursor))
        digits += sourceCode[cursor++];

    return digits;
}

std::string Tokenizer::getStringToken(const std::string& sourceCode, const unsigned int& index)
{
    unsigned int cursor = index;

    std::string string;
    while(sourceCode[++cursor] != '"')
        string += sourceCode[cursor];

    return string;
}

std::string Tokenizer::getSymbolToken(const std::string& sourceCode, const unsigned int& index)
{
    unsigned int cursor = index;

    std::string symbol;
    while(symbolTokenMatch(sourceCode, cursor))
        symbol += sourceCode[cursor++];

    return symbol;
}

std::string Tokenizer::getCommentToken(const std::string& sourceCode, const unsigned int& index)
{
    unsigned int cursor = index + 2;

    std::string comment;
    while(sourceCode[cursor] != '\n')
        comment += sourceCode[cursor++];
    
    return comment;
}