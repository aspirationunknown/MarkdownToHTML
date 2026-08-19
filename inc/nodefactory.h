#ifndef NODE_FACTORY_H
#define NODE_FACTORY_H

#include "node.h"

class NodeFactory {
public:
    NodeFactory() = default;
    ~NodeFactory() = default;
    NodeFactory(NodeFactory&) = delete;
    NodeFactory& operator=(NodeFactory&) = delete;
    NodeFactory(NodeFactory&&) = delete;
    NodeFactory&& operator=(NodeFactory&&) = delete;

    Node* CreateNode(std::string symbol);

private:

};



#endif //NODE_FACTORY_H
