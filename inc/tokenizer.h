#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <fstream>
#include <memory>
#include <string>

#include "tokenqueue.h"

class Tokenizer {
public:
    Tokenizer() = delete;
    Tokenizer(std::string input_file_name, std::shared_ptr<TokenQueue> token_queue);
    virtual ~Tokenizer() = default;
    Tokenizer(Tokenizer&) = delete;
    Tokenizer& operator=(Tokenizer&) = delete;
    Tokenizer(Tokenizer&&) = delete;
    Tokenizer&& operator=(Tokenizer&&) = delete;

    std::weak_ptr<TokenQueue> GetQueue();
    virtual void Tokenize() = 0;

protected:
    std::string input_file_name_;
    std::ifstream input_file_;
    std::shared_ptr<TokenQueue> token_queue_;
};

#endif //TOKENIZER_H
