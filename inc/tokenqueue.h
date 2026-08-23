#ifndef TOKEN_QUEUE_H
#define TOKEN_QUEUE_H

#include <cstddef>
#include <deque>

#include "formats.h"

class TokenQueue {
public:
    TokenQueue() {}
    ~TokenQueue() {}

    Formats Pop();
    void Push(Formats);
    std::size_t Size();

private:
    std::deque<Formats> token_queue_;
};

#endif //TOKEN_QUEUE_H
