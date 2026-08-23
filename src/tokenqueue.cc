#include "tokenqueue.h"

void TokenQueue::Push(Formats node) {
    token_queue_.push_back(node);
}

std::size_t TokenQueue::Size() {
    return token_queue_.size();
}

Formats TokenQueue::Pop() {
    Formats element = token_queue_.front();
    token_queue_.pop_front();

    return element;

}
