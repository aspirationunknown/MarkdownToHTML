#include <iostream>
#include <memory>
#include <system_error>

#include "tokenizer.h"
#include "tokenqueue.h"

Tokenizer::Tokenizer(std::string input_file_name, std::shared_ptr<TokenQueue> token_queue) : input_file_name_(input_file_name), token_queue_(token_queue) {}

std::weak_ptr<TokenQueue> Tokenizer::GetQueue() {
    return token_queue_;
}
