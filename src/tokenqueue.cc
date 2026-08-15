#include "tokenqueue.h"
#include <memory>

void TokenQueue::Push(std::unique_ptr<Node> node) {
    token_queue_.push_back(std::move(node));
}

std::size_t TokenQueue::Size() {
    return token_queue_.size();
}

std::unique_ptr<Node> TokenQueue::Pop() {
    std::unique_ptr<Node> element = std::move(token_queue_.front());
    token_queue_.pop_front();

    return std::move(element);

}
