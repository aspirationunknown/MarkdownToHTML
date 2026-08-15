#include <memory>
#include <system_error>

#include "tokenizer.h"
#include "tokenqueue.h"

Tokenizer::Tokenizer(std::string input_file_name, std::shared_ptr<TokenQueue> token_queue) : input_file_name_(input_file_name), token_queue_(token_queue) {
        input_file_.open(input_file_name_);
        if(!input_file_) {
            throw std::system_error(
                std::make_error_code(std::errc::bad_file_descriptor)
            );
        }
}

Tokenizer::~Tokenizer() {
    input_file_.close();
}

std::weak_ptr<TokenQueue> Tokenizer::GetQueue() {
    return token_queue_;
}
