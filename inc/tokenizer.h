#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <array>
#include <fstream>
#include <memory>
#include <string>

#include "tokenqueue.h"

class Tokenizer {
public:
    Tokenizer() = delete;
    Tokenizer(std::string input_file_name, std::shared_ptr<TokenQueue> token_queue);
    ~Tokenizer();
    Tokenizer(Tokenizer&) = delete;
    Tokenizer& operator=(Tokenizer&) = delete;
    Tokenizer(Tokenizer&&) = delete;
    Tokenizer&& operator=(Tokenizer&&) = delete;

    std::weak_ptr<TokenQueue> GetQueue();
    void Tokenize();

private:
    std::string ProcessLine(std::string line);

    std::string input_file_name_;
    std::ifstream input_file_;
    std::shared_ptr<TokenQueue> token_queue_;
    std::array<std::string, 1> symbols{"#"};
};

#endif //TOKENIZER_H
