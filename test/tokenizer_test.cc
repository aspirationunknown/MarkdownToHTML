#include <gtest/gtest.h>

#include <system_error>
#include <string>

#include "formats.h"
#include "tokenizer.h"
#include "tokenqueue.h"

TEST(TokenizerTest, TokenizerConstructionTest) {
    std::string input_file_name{"notes/HtmlNotes.md"};

    try {
        auto tq = std::make_shared<TokenQueue>();
        Tokenizer tokenizer{input_file_name, tq};
        SUCCEED();
    } catch(std::system_error& err) {
        FAIL();
    }
}

TEST(TokenizerTest, TokenizerFailedConstructionTest) {
    std::string bad_input_file_name{"notes/Fake.md"};

    try {
        auto tq = std::make_shared<TokenQueue>();
        Tokenizer tokenizer{bad_input_file_name, tq};
        FAIL();
    } catch (std::system_error& err) {
        SUCCEED();
    }
}

TEST(TokenizerTest, GetQueueTest) {
    std::string input_file_name{"data/SimpleInputFile.md"};

    try {
        auto tq = std::make_shared<TokenQueue>();
        Tokenizer tokenizer{input_file_name, tq};
        auto queue_ptr = tokenizer.GetQueue();

        if (auto q = queue_ptr.lock()) {
            ASSERT_EQ(q->Size(), 0); // just checks that the queue was retrieved
        } else {
            FAIL();
        }
    } catch (std::system_error err) {
        FAIL();
    }
}

TEST(TokenizerTest, TokenizeTest) {
    std::string input_file_name{"data/TextInputFile.md"};
    auto tq = std::make_shared<TokenQueue>();

    try {
        Tokenizer tokenizer{input_file_name, tq};
        tokenizer.Tokenize();
        auto queue_ptr = tokenizer.GetQueue();
        if (auto q = queue_ptr.lock()) {
            ASSERT_EQ(q->Size(), 5);
        }
    } catch (std::system_error err) {
        FAIL();
    }

}

TEST(TokenizerTest, ProcessLineTest) {
    std::string line{"This is a plain text line.\n"};
    try {
        std::string input_file_name{"data/PlainTextLine.md"};
        auto tq = std::make_shared<TokenQueue>();
        Tokenizer tokenizer{input_file_name, tq};
        tokenizer.Tokenize();
        if (auto q = tokenizer.GetQueue().lock()) {
            ASSERT_EQ(q->Size(), 1);
            auto front = q->Pop();
            auto elem = std::get_if<PlainText>(&front);
            if (elem) {
                ASSERT_EQ(elem->GetText(), line);
            } else {
                FAIL();
            }
        }
    } catch (std::system_error err) {
        FAIL();
    }
}
