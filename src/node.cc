#include "node.h"

BoldTextNode::BoldTextNode(std::string text): text_(text) {}

void BoldTextNode::accept(Visitor& visitor) {}
