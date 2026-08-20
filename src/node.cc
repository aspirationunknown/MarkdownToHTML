#include "node.h"

BoldTextNode::BoldTextNode(std::string text): Node(text) {}

void BoldTextNode::Accept(Visitor& visitor) {}
