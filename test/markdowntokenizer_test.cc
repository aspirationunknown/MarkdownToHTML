#include <gtest/gtest.h>

#include <string>
#include <system_error>

#include "formats.h"
#include "markdowntokenizer.h"
#include "tokenqueue.h"

TEST(MarkdownTokenizerTest, ConstructionTest) {
  std::string input_file_name{"notes/HtmlNotes.md"};

  try {
    auto token_queue = std::make_shared<TokenQueue>();
    MarkdownTokenizer tokenizer{input_file_name, token_queue};
    SUCCEED();
  } catch (std::system_error &err) {
    FAIL();
  }
}

TEST(MarkdownTokenizerTest, FailedConstructionTest) {
  std::string bad_input_file_name{"notes/Fake.md"};

  try {
    auto token_queue = std::make_shared<TokenQueue>();
    MarkdownTokenizer tokenizer{bad_input_file_name, token_queue};
    FAIL();
  } catch (std::system_error &err) {
    SUCCEED();
  }
}

TEST(MarkdownTokenizerTest, GetQueueTest) {
  std::string input_file_name{"data/SimpleInputFile.md"};

  try {
    auto token_queue = std::make_shared<TokenQueue>();
    MarkdownTokenizer tokenizer{input_file_name, token_queue};
    auto queue_ptr = tokenizer.GetQueue();

    if (auto queue = queue_ptr.lock()) {
      ASSERT_EQ(queue->Size(), 0); // just checks that the queue was retrieved
    } else {
      FAIL();
    }
  } catch (std::system_error err) {
    FAIL();
  }
}

TEST(MarkdownTokenizerTest, TokenizeTest) {
  std::string input_file_name{"data/TextInputFile.md"};
  auto token_queue = std::make_shared<TokenQueue>();

  try {
    MarkdownTokenizer tokenizer{input_file_name, token_queue};
    tokenizer.Tokenize();
    auto queue_ptr = tokenizer.GetQueue();
    if (auto queue = queue_ptr.lock()) {
      ASSERT_EQ(queue->Size(), 5);
    }
  } catch (std::system_error err) {
    FAIL();
  }
}

TEST(MarkdownTokenizerTest, ProcessLineTest) {
  std::string line{"This is a plain text line."};
  try {
    std::string input_file_name{"data/PlainTextLine.md"};
    auto token_queue = std::make_shared<TokenQueue>();
    MarkdownTokenizer tokenizer{input_file_name, token_queue};
    tokenizer.Tokenize();
    if (auto queue = tokenizer.GetQueue().lock()) {
      ASSERT_EQ(queue->Size(), 1);
      auto front = queue->Pop();

      if (auto *elem = std::get_if<PlainText>(&front); elem) {
        ASSERT_EQ(elem->GetText(), line);
      } else {
        FAIL();
      }
    }
  } catch (std::system_error err) {
    FAIL();
  }
}
