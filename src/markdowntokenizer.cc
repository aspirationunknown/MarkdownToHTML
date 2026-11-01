#include <iostream>

#include "markdowntokenizer.h"
#include "tokenqueue.h"

MarkdownTokenizer::MarkdownTokenizer(std::string input_file_name,
                                     std::shared_ptr<TokenQueue> queue)
    : Tokenizer(std::move(input_file_name), std::move(queue)) {
  input_file_.open(input_file_name_);
  if (!input_file_) {
    throw std::system_error(
        std::make_error_code(std::errc::bad_file_descriptor));
  }
}

MarkdownTokenizer::~MarkdownTokenizer() { input_file_.close(); }

void MarkdownTokenizer::Tokenize() {
  std::string line{};
  std::string processed_line{};
  while (getline(input_file_, line)) {
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
