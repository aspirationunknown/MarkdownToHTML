#include <gtest/gtest.h>
#include <memory>

#include "node.h"
#include "tokenqueue.h"

TEST(TokenQueueTest, PushTest) {
    TokenQueue token_queue{};
    auto empty_bold_text_node = std::make_unique<BoldTextNode>("Some words");

    if (token_queue.Size() != 0) {
        FAIL();
    }

    token_queue.Push(std::move(empty_bold_text_node));

    if (token_queue.Size() == 1) {
        SUCCEED();
    } else {
        FAIL();
    }
}
