#include "nodefactory.h"
#include "node.h"
#include <memory>

std::unique_ptr<Node> NodeFactory::CreateBoldTextNode(std::string text) {
    return std::make_unique<BoldTextNode>(text);
}

std::unique_ptr<Node> NodeFactory::CreateItalicTextNode(std::string text) {
    return std::make_unique<ItalicTextNode>(text);
}

std::unique_ptr<Node> NodeFactory::CreateBoldItalicTextNode(std::string text) {
    return std::make_unique<BoldItalicTextNode>(text);
}

std::unique_ptr<Node> NodeFactory::CreatePlainTextNode(std::string text) {
    return std::make_unique<PlainTextNode>(text);
}

std::unique_ptr<Node> NodeFactory::CreateTitleNode(std::string text) {
    return std::make_unique<TitleNode>(text);
}

std::unique_ptr<Node> NodeFactory::CreateHeaderNode(std::string text, unsigned short lvl) {
    return std::make_unique<HeaderNode>(text, lvl);
}

std::unique_ptr<Node> NodeFactory::CreateUnorderedListNode(std::string text) {
    return std::make_unique<UnorderedListNode>(text);
}

std::unique_ptr<Node> NodeFactory::CreateOrderedListNode(std::string text, unsigned short rank) {
    return std::make_unique<OrderedListNode>(text, rank);
}

std::unique_ptr<Node> NodeFactory::CreateImageNode(std::string url) {
    return std::make_unique<ImageNode>(url);
}

std::unique_ptr<Node> NodeFactory::CreateHyperlinkNode(std::string url) {
    return std::make_unique<HyperlinkNode>(url);
}

std::unique_ptr<Node> NodeFactory::CreateBlockQuoteNode(std::string text) {
    return std::make_unique<BlockQuoteNode>(text);
}

std::unique_ptr<Node> NodeFactory::CreateInlineCodeNode(std::string text) {
    return std::make_unique<InlineCodeNode>(text);
}
std::unique_ptr<Node> NodeFactory::CreateCodeBlockNode(std::string text) {
    return std::make_unique<CodeBlockNode>(text);
}
std::unique_ptr<Node> NodeFactory::CreateHorizontalRuleNode() {
    return std::make_unique<HorizontalRuleNode>();
}
