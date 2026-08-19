#include "nodefactory.h"

Node* NodeFactory::CreateNode(std::string symbol) {
    if (symbol == "# ") {
        // header 1 or title
    } else if (symbol == "## ") {
        // header 2
    } else if (symbol == "### ") {
        // header 3
    } else if (symbol == "#### ") {
        // header 4
    } else if (symbol == "##### ") {
        // header 5
    } else if (symbol == "*" || symbol == "_") {
        // italic text
    } else if (symbol == "**" || symbol == "__") {
        // bold text
    } else if (symbol == "***" || symbol == "___") {
        // bold italic text
    } else if (symbol == "") {
        // plain text
    } else if (symbol == "- " || symbol == "+ " || symbol == "* ") {
        // unordered list
    } else if (/* handle ordered list */ false) {
        // ordered list
    }
    return nullptr;
}
