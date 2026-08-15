#include <gtest/gtest.h>

#include <system_error>
#include <string>

#include "tokenizer.h"

TEST(TokenizerTest, TokenizerConstructionTest) {
    std::string input_file_name{"notes/HtmlNotes.md"};
    try {
        Tokenizer tokenizer{input_file_name};
        SUCCEED();
    } catch(std::system_error& err) {
        FAIL();
    }
}

TEST(TokenizerTest, TokenizerFailedConstructionTest) {
    std::string bad_input_file_name{"notes/Fake.md"};

    try {
        Tokenizer tokenizer{bad_input_file_name};
        FAIL();
    } catch (std::system_error& err) {
        SUCCEED();
    }
}
