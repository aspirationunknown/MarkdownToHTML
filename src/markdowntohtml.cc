#include <iostream>
#include <system_error>

#include "markdowntohtml.h"
#include "markdowntokenizer.h"
#include "tokenqueue.h"

int run_application(const std::span<char *> &args) {

  try {
    auto token_queue = std::make_shared<TokenQueue>();
    MarkdownTokenizer tokenizer(args[0], token_queue);
  } catch (std::system_error err) {
    std::cerr << "Failed to open file, error: " << err.what() << "\n";
  }

  return 0;
}
