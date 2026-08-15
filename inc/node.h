#ifndef AST_H
#define AST_H

#include <string>

#include "visitor.h"

// Abstract base class for all nodes in the Abstract Syntax Tree (AST)
struct Node {
public:
    virtual ~Node() {}
    virtual void accept(Visitor&) = 0;
};

struct TitleNode : public Node {};

struct HeaderNode : public Node {};

struct BoldTextNode : public Node {
public:
    BoldTextNode() = delete;
    BoldTextNode(std::string text);
    ~BoldTextNode() = default;

    void accept(Visitor& visitor);

private:
    std::string text_;
};

struct ItalicTextNode : public Node {};

struct BoldItalicTextNode : public Node {};

struct PlainTextNode : public Node {};

struct BlockQuoteNode : public Node {};

struct OrderedListNode : Node {};

struct UnorderedListNode : Node {};

struct InlineCodeNode : Node {};

struct CodeBlockNode : Node {};

struct HorizontalRuleNode : Node {};

struct URLLinkNode : Node {};

struct ImageNode : Node {};

#endif // AST_H
