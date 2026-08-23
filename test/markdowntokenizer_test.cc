#include <gtest/gtest.h>

#include <system_error>
#include <string>

#include "formats.h"
#include "markdowntokenizer.h"
#include "tokenqueue.h"

TEST(MarkdownTokenizerTest, ConstructionTest) {
    std::string input_file_name{"notes/HtmlNotes.md"};

    try {
        auto tq = std::make_shared<TokenQueue>();
        MarkdownTokenizer tokenizer{input_file_name, tq};
        SUCCEED();
    } catch(std::system_error& err) {
        FAIL();
    }
}

TEST(MarkdownTokenizerTest, FailedConstructionTest) {
    std::string bad_input_file_name{"notes/Fake.md"};

    try {
        auto tq = std::make_shared<TokenQueue>();
        MarkdownTokenizer tokenizer{bad_input_file_name, tq};
        FAIL();
    } catch (std::system_error& err) {
        SUCCEED();
    }
}

TEST(MarkdownTokenizerTest, GetQueueTest) {
    std::string input_file_name{"data/SimpleInputFile.md"};

    try {
        auto tq = std::make_shared<TokenQueue>();
        MarkdownTokenizer tokenizer{input_file_name, tq};
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

TEST(MarkdownTokenizerTest, TokenizeTest) {
    std::string input_file_name{"data/TextInputFile.md"};
    auto tq = std::make_shared<TokenQueue>();

    try {
        MarkdownTokenizer tokenizer{input_file_name, tq};
        tokenizer.Tokenize();
        auto queue_ptr = tokenizer.GetQueue();
        if (auto q = queue_ptr.lock()) {
            ASSERT_EQ(q->Size(), 5);
        }
    } catch (std::system_error err) {
        FAIL();
    }

}

TEST(MarkdownTokenizerTest, ProcessLineTest) {
    std::string line{"This is a plain text line."};
    try {
        std::string input_file_name{"data/PlainTextLine.md"};
        auto tq = std::make_shared<TokenQueue>();
        MarkdownTokenizer tokenizer{input_file_name, tq};
        tokenizer.Tokenize();
        if (auto q = tokenizer.GetQueue().lock()) {
            ASSERT_EQ(q->Size(), 1);
            auto front = q->Pop();

            if (auto elem = std::get_if<PlainText>(&front); elem) {
                ASSERT_EQ(elem->GetText(), line);
            } else {
                FAIL();
            }
        }
    } catch (std::system_error err) {
        FAIL();
    }
}
