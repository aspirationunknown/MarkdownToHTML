#include <gtest/gtest.h>

#include "formats.h"
#include "tokenqueue.h"

TEST(TokenQueueTest, PushTest) {
    TokenQueue token_queue{};
    auto bold_text_node = Formats{ BoldText{("Some words")} };

    ASSERT_EQ(token_queue.Size(), 0);

    token_queue.Push(bold_text_node);

    ASSERT_EQ(token_queue.Size(), 1);
}

TEST(TokenQueueTest, PopTest) {
    TokenQueue token_queue{};
    auto bold_text_node = Formats{ BoldText{("Some words")} };
    token_queue.Push(bold_text_node);

    ASSERT_EQ(token_queue.Size(), 1);

    auto retrieved_node = token_queue.Pop();

    ASSERT_EQ(token_queue.Size(), 0);
}
