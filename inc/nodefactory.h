#ifndef NODE_FACTORY_H
#define NODE_FACTORY_H

#include "node.h"
#include <memory>

class NodeFactory {
public:
    NodeFactory() = default;
    ~NodeFactory() = default;
    NodeFactory(NodeFactory&) = delete;
    NodeFactory& operator=(NodeFactory&) = delete;
    NodeFactory(NodeFactory&&) = delete;
    NodeFactory&& operator=(NodeFactory&&) = delete;

    std::unique_ptr<Node> CreateBoldTextNode(std::string text);
    std::unique_ptr<Node> CreateItalicTextNode(std::string text);
    std::unique_ptr<Node> CreateBoldItalicTextNode(std::string text);
    std::unique_ptr<Node> CreatePlainTextNode(std::string text);
    std::unique_ptr<Node> CreateTitleNode(std::string text);
    std::unique_ptr<Node> CreateHeaderNode(std::string text, unsigned short lvl);
    std::unique_ptr<Node> CreateUnorderedListNode(std::string text);
    std::unique_ptr<Node> CreateOrderedListNode(std::string text, unsigned short rank);
    std::unique_ptr<Node> CreateImageNode(std::string url);
    std::unique_ptr<Node> CreateHyperlinkNode(std::string url);
    std::unique_ptr<Node> CreateBlockQuoteNode(std::string text);
    std::unique_ptr<Node> CreateInlineCodeNode(std::string text);
    std::unique_ptr<Node> CreateCodeBlockNode(std::string text);
    std::unique_ptr<Node> CreateHorizontalRuleNode();

private:

};



#endif //NODE_FACTORY_H
