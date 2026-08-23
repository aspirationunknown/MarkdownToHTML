#ifndef AST_H
#define AST_H

#include <string>
#include <variant>

struct Title {
    Title() = delete;
    Title(std::string text);
    ~Title() = default;

    std::string GetText();

private:
    std::string text_;
};

struct Header {
public:
    Header() = delete;
    Header(std::string text, unsigned short lvl);
    ~Header() = default;

    unsigned short GetLevel();
    std::string GetText();

private:
    unsigned short lvl_;
    std::string text_;
};

struct BoldText {
    BoldText() = delete;
    BoldText(std::string text);
    ~BoldText() = default;

    std::string GetText();

private:
    std::string text_;
};

struct ItalicText {
    ItalicText() = delete;
    ItalicText(std::string text);
    ~ItalicText() = default;

    std::string GetText();

private:
    std::string text_;
};

struct BoldItalicText {
    BoldItalicText() = delete;
    BoldItalicText(std::string text);
    ~BoldItalicText() = default;

    std::string GetText();

private:
    std::string text_;
};

struct PlainText {
    PlainText() = delete;
    PlainText(std::string text);
    ~PlainText() = default;

    std::string GetText();

private:
    std::string text_;
};

struct BlockQuote {
    BlockQuote() = delete;
    BlockQuote(std::string text);
    ~BlockQuote() = default;

    std::string GetText();

private:
    std::string text_;
};

struct OrderedList {
public:
    OrderedList() = delete;
    OrderedList(std::string text, unsigned short rank);
    ~OrderedList() = default;

    unsigned short GetRank();
    std::string GetText();

private:
    unsigned short rank_;
    std::string text_;
};

struct UnorderedList {
    UnorderedList() = delete;
    UnorderedList(std::string text);
    ~UnorderedList() = default;

    std::string GetText();

private:
    std::string text_;
};

struct InlineCode {
    InlineCode() = delete;
    InlineCode(std::string text);
    ~InlineCode() = default;

    std::string GetText();

private:
    std::string text_;
};

struct CodeBlock {
    CodeBlock() = delete;
    CodeBlock(std::string text);
    ~CodeBlock() = default;

    std::string GetText();

private:
    std::string text_;
};

struct HorizontalRule {
    HorizontalRule() = default;
    ~HorizontalRule() = default;

};

struct Hyperlink {
    Hyperlink() = delete;
    Hyperlink(std::string text, std::string url);
    ~Hyperlink() = default;

    std::string GetText();
    std::string GetUrl();

private:
    std::string text_;
    std::string url_;
};

struct Image {
    Image() = delete;
    Image(std::string alt, std::string url);
    ~Image() = default;

    std::string GetAlt();
    std::string GetUrl();

private:
    std::string alt_;
    std::string url_;
};

using Formats = std::variant<
std::monostate,
Title,
Header,
BoldText,
ItalicText,
BoldItalicText,
PlainText,
BlockQuote,
UnorderedList,
OrderedList,
InlineCode,
CodeBlock,
HorizontalRule,
Hyperlink,
Image
>;

#endif // AST_H
