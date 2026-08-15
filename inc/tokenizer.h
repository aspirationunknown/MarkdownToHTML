#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <fstream>
#include <string>

class Tokenizer {
public:
    Tokenizer(std::string input_file_name);
    ~Tokenizer();

private:
    std::string input_file_name_;
    std::ifstream input_file_;
};

#endif //TOKENIZER_H
