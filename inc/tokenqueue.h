#ifndef TOKEN_QUEUE_H
#define TOKEN_QUEUE_H

#include <deque>

#include "ast.h"

class TokenQueue {
public:
    TokenQueue() {}
    ~TokenQueue() {}

private:
    std::deque<Node*> token_queue_;
};

#endif //TOKEN_QUEUE_H
