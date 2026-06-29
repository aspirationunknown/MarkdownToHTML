#include <fstream>
#include <iostream>

#include "markdownconverter.h"

InputFileStatus MarkdownConverter::ReadInputFile() {
    auto result{InputFileStatus::Ok};
    std::ifstream input_file;
    input_file.open(input_file_name_, std::ios::in);
    if (!input_file) {
        result = InputFileStatus::Failed_To_Open; // Failure to open input file
    } else {
        std::string line{};
        while (getline(input_file, line)) {
            std::cout << line << std::endl;
        }
    }

    return result;
}
