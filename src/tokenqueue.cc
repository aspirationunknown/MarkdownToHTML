#include "tokenqueue.h"

void TokenQueue::Push(std::unique_ptr<Node> node) {
    token_queue_.push_back(std::move(node));
}

std::size_t TokenQueue::Size() {
    return token_queue_.size();
}
