#include <iostream>
#include <vector>

#include "markdownconverter.h"

MarkdownConverter::MarkdownConverter(std::string input_file_name) : Converter(input_file_name) {
}

MarkdownConverter::~MarkdownConverter() {
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

std::vector<StyledText> MarkdownConverter::ProcessInputLine(std::string input_line) {
    std::vector<StyledText> result{};
    ParseInput(input_line, result);

    return result;
}

void MarkdownConverter::ParseInput(std::string input_line, std::vector<StyledText>& result) {
    for (auto delim : tags) {
        if (delim == "") {
            // skipping NoStyle
            continue;
        }


    }
}
