#ifndef AST_H
#define AST_H

#include "visitor.h"

// Abstract base class for all nodes in the Abstract Syntax Tree (AST)
struct Node {
    virtual ~Node() {}
    virtual void accept(Visitor& visitor) = 0;
};

struct TitleNode : public Node {};

struct HeaderNode : public Node {};

struct TextNode : public Node {};

struct BoldTextNode : public TextNode {};

struct ItalicTextNode : public TextNode {};

struct BoldItalicTextNode : public TextNode {};

struct PlainTextNode : public TextNode {};

struct BlockQuoteNode : public Node {};

struct ListNode : Node {};

struct OrderedListNode : ListNode {};

struct UnorderedListNode : ListNode {};

struct InlineCodeNode : Node {};

struct CodeBlockNode : Node {};

struct HorizontalRuleNode : Node {};

struct URLLinkNode : Node {};

struct ImageNode : Node {};

#endif // AST_H
