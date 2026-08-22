#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <array>
#include <fstream>
#include <memory>
#include <string>

#include "tokenqueue.h"

class Tokenizer {
public:
    Tokenizer() = delete;
    Tokenizer(std::string input_file_name, std::shared_ptr<TokenQueue> token_queue);
    ~Tokenizer();
    Tokenizer(Tokenizer&) = delete;
    Tokenizer& operator=(Tokenizer&) = delete;
    Tokenizer(Tokenizer&&) = delete;
    Tokenizer&& operator=(Tokenizer&&) = delete;

    std::weak_ptr<TokenQueue> GetQueue();
    void Tokenize();

private:
    std::string ProcessLine(std::string line);

    std::string input_file_name_;
    std::ifstream input_file_;
    std::shared_ptr<TokenQueue> token_queue_;
    std::array<std::string, 20> symbols{
        "#",// Title or Header 1
        "##",// Header 2
        "###",// Header 3
        "####",// Header 4
        "#####",// Header 5
        "*",// Italic or Unordered List Item
        "**",// Bold
        "***",// Bold&Italic or Horizontal Rule
        "_",// Italic
        "__",// Bold
        "___",// Bold&Italic or Horizontal Rule
        "-",// Unordered List Item
        "+",// Unordered List Item
        "---",// Horizontal Rule
        ">",// Block Quote
        "`", // Inline Code
        "'''",// Code Block
        "#.", // Numbered List Item, numbers can keep increasing
        "[text](url)",// Hyperlink
        "![alt](url)" // Image
    };
};

#endif //TOKENIZER_H
