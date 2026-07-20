#include <iostream>

#include "converter.h"

Converter::Converter() {
    input_file_.open(input_file_name_, std::ios::in);
}

Converter::Converter(std::string input_file_name) : input_file_name_(input_file_name) {
    Converter();
}

Converter::~Converter() {
    input_file_.close();
}

InputFileStatus Converter::ReadInputFile() {
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

std::string Converter::GetInputFileBaseName() {
    std::string result{input_file_name_};
    // strip path
    auto pos_path_end = input_file_name_.find_last_of("/\\");
    if (pos_path_end != std::string::npos) {
        result = result.substr(pos_path_end + 1);
    }
    // strip extension
    auto pos_ext_begin = result.find_last_of(".");
    if (pos_ext_begin != std::string::npos) {
        result = result.substr(0, pos_ext_begin);
    }
    // return the file base name
    return result;
}
