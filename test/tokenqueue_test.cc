#include <gtest/gtest.h>

#include "node.h"
#include "tokenqueue.h"

TEST(TokenQueueTest, PushTest) {
    TokenQueue token_queue{};
    auto bold_text_node = std::make_unique<BoldTextNode>("Some words");

    ASSERT_EQ(token_queue.Size(), 0);

    token_queue.Push(std::move(bold_text_node));

    ASSERT_EQ(token_queue.Size(), 1);
}
