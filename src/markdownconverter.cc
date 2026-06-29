#include <iostream>

#include "markdownconverter.h"

MarkdownConverter::MarkdownConverter() {
    input_file_.open(input_file_name_, std::ios::in);
}

MarkdownConverter::MarkdownConverter(std::string input_file_name) : input_file_name_(input_file_name) {
    MarkdownConverter();
}

MarkdownConverter::~MarkdownConverter() {
    input_file_.close();
}

InputFileStatus MarkdownConverter::ReadInputFile() {
    auto result{InputFileStatus::Ok};

    input_file_.open(input_file_name_, std::ios::in);
    if (!input_file_) {
        result = InputFileStatus::Failed_To_Open; // Failure to open input file
    } else {
        std::string line{};
        while (getline(input_file_, line)) {
            std::cout << line << std::endl;
        }
    }

    return result;
}
