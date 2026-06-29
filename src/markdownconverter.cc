#include <fstream>
#include <iostream>

#include "markdownconverter.h"

unsigned int MarkdownConverter::ReadInputFile() {
    unsigned int result{0u};
    std::ifstream input_file;
    input_file.open(input_file_name_, std::ios::in);
    if (!input_file) {
        result = 1u; // Failure to open input file
    } else {
        std::string line{};
        while (getline(input_file, line)) {
            std::cout << line << std::endl;
        }
    }

    return result;
}
