#include <iostream>

#include "markdowntokenizer.h"
#include "tokenqueue.h"

MarkdownTokenizer::MarkdownTokenizer(std::string input_file_name,
                                     std::shared_ptr<TokenQueue> queue)
    : Tokenizer(std::move(input_file_name), std::move(queue)) {}

void MarkdownTokenizer::Tokenize() {
  std::string line{};
  std::string processed_line{};
  while (GetLine(line)) {
    processed_line = ProcessLine(line);
  }
}

std::string MarkdownTokenizer::ProcessLine(const std::string &line) {
  std::string result{};
  for (const auto &character : line) {
    std::cout << "'" << character << "'\n";
  }
  return result; // Placeholder
}
