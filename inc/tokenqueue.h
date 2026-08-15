#ifndef TOKEN_QUEUE_H
#define TOKEN_QUEUE_H

#include <cstddef>
#include <deque>
#include <memory>

#include "node.h"

class TokenQueue {
public:
    TokenQueue() {}
    ~TokenQueue() {}

    void Push(std::unique_ptr<Node>);
    std::size_t Size();

private:
    std::deque<std::unique_ptr<Node>> token_queue_;
};

#endif //TOKEN_QUEUE_H
