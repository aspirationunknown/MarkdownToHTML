#ifndef AST_H
#define AST_H

#include <string>

#include "visitor.h"

// Abstract base class for all nodes in the Abstract Syntax Tree (AST)
struct Node {
public:
    explicit Node();
    explicit Node(std::string text): text_(text) {}
    virtual ~Node() {}
    virtual void Accept(Visitor&) = 0;

protected:
    std::string text_;
};

struct TitleNode : public Node {
    TitleNode() = delete;
    TitleNode(std::string text);
    ~TitleNode() = default;

    void Accept(Visitor& visitor) override;
};

struct HeaderNode : public Node {
public:
    HeaderNode() = delete;
    HeaderNode(std::string text, unsigned short lvl);
    ~HeaderNode() = default;

    void Accept(Visitor& visitor) override;
    unsigned short GetLevel();

private:
    unsigned short lvl_;
};

struct BoldTextNode : public Node {
    BoldTextNode() = delete;
    BoldTextNode(std::string text);
    ~BoldTextNode() = default;

    void Accept(Visitor& visitor) override;
};

struct ItalicTextNode : public Node {
    ItalicTextNode() = delete;
    ItalicTextNode(std::string text);
    ~ItalicTextNode() = default;

    void Accept(Visitor& visitor) override;
};

struct BoldItalicTextNode : public Node {
    BoldItalicTextNode() = delete;
    BoldItalicTextNode(std::string text);
    ~BoldItalicTextNode() = default;

    void Accept(Visitor& visitor) override;
};

struct PlainTextNode : public Node {
    PlainTextNode() = delete;
    PlainTextNode(std::string text);
    ~PlainTextNode() = default;

    void Accept(Visitor& visitor) override;
};

struct BlockQuoteNode : public Node {
    BlockQuoteNode() = delete;
    BlockQuoteNode(std::string text);
    ~BlockQuoteNode() = default;

    void Accept(Visitor& visitor) override;
};

struct OrderedListNode : Node {
public:
    OrderedListNode() = delete;
    OrderedListNode(std::string text, unsigned short rank);
    ~OrderedListNode() = default;

    void Accept(Visitor& visitor) override;
    unsigned short GetRank();

private:
    unsigned short rank_;
};

struct UnorderedListNode : Node {
    UnorderedListNode() = delete;
    UnorderedListNode(std::string text);
    ~UnorderedListNode() = default;

    void Accept(Visitor& visitor) override;
};

struct InlineCodeNode : Node {
    InlineCodeNode() = delete;
    InlineCodeNode(std::string text);
    ~InlineCodeNode() = default;

    void Accept(Visitor& visitor) override;
};

struct CodeBlockNode : Node {
    CodeBlockNode() = delete;
    CodeBlockNode(std::string text);
    ~CodeBlockNode() = default;

    void Accept(Visitor& visitor) override;
};

struct HorizontalRuleNode : Node {
    HorizontalRuleNode() = default;
    ~HorizontalRuleNode() = default;

    void Accept(Visitor& visitor) override;
};

struct HyperlinkNode : Node {
    HyperlinkNode() = delete;
    HyperlinkNode(std::string url);
    ~HyperlinkNode() = default;

    void Accept(Visitor& visitor) override;
};

struct ImageNode : Node {
    ImageNode() = delete;
    ImageNode(std::string url);
    ~ImageNode() = default;

    void Accept(Visitor& visitor) override;
};

#endif // AST_H
