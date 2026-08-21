#include "node.h"

TitleNode::TitleNode(std::string text): Node(text) {}

void TitleNode::Accept(Visitor& visitor) {}

HeaderNode::HeaderNode(std::string text, unsigned short lvl): Node(text), lvl_(lvl) {}

void HeaderNode::Accept(Visitor& visitor) {}

unsigned short HeaderNode::GetLevel() {
    return lvl_;
}

BoldTextNode::BoldTextNode(std::string text): Node(text) {}

void BoldTextNode::Accept(Visitor& visitor) {}

ItalicTextNode::ItalicTextNode(std::string text): Node(text) {}

void ItalicTextNode::Accept(Visitor& visitor) {}

BoldItalicTextNode::BoldItalicTextNode(std::string text): Node(text) {}

void BoldItalicTextNode::Accept(Visitor& visitor) {}

PlainTextNode::PlainTextNode(std::string text): Node(text) {}

void PlainTextNode::Accept(Visitor& visitor) {}

BlockQuoteNode::BlockQuoteNode(std::string text): Node(text) {}

void BlockQuoteNode::Accept(Visitor& visitor) {}

OrderedListNode::OrderedListNode(std::string text, unsigned short rank): Node(text), rank_(rank) {}

void OrderedListNode::Accept(Visitor& visitor) {}

unsigned short OrderedListNode::GetRank() {
    return rank_;
}

UnorderedListNode::UnorderedListNode(std::string text): Node(text) {}

void UnorderedListNode::Accept(Visitor& visitor) {}

InlineCodeNode::InlineCodeNode(std::string text): Node(text) {}

void InlineCodeNode::Accept(Visitor& visitor) {}

CodeBlockNode::CodeBlockNode(std::string text): Node(text) {}

void CodeBlockNode::Accept(Visitor& visitor) {}

void HorizontalRuleNode::Accept(Visitor& visitor) {}

HyperlinkNode::HyperlinkNode(std::string url): Node(url) {}

void HyperlinkNode::Accept(Visitor& visitor) {}

ImageNode::ImageNode(std::string url): Node(url) {}

void ImageNode::Accept(Visitor& visitor) {}
