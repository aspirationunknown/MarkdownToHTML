#ifndef MARKDOWN_TOKENIZER_H
#define MARKDOWN_TOKENIZER_H

#include <array>

#include "tokenizer.h"


class MarkdownTokenizer : public Tokenizer {
public:
    MarkdownTokenizer() = delete;
    MarkdownTokenizer(std::string input_file_name, std::shared_ptr<TokenQueue> token_queue);
    ~MarkdownTokenizer();
    MarkdownTokenizer(MarkdownTokenizer&) = delete;
    MarkdownTokenizer& operator=(MarkdownTokenizer&) = delete;
    MarkdownTokenizer(MarkdownTokenizer&&) = delete;
    MarkdownTokenizer&& operator=(MarkdownTokenizer&&) = delete;

    void Tokenize();

private:
    std::string ProcessLine(std::string line);

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

#endif //MARKDOWN_TOKENIZER_H
