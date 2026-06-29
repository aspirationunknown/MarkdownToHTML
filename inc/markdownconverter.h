#include <string>

class MarkdownConverter {
public:
    MarkdownConverter() : input_file_name_("") {}
    MarkdownConverter(std::string input_file_name) : input_file_name_(input_file_name) {}
    ~MarkdownConverter() {}

    const std::string GetInputFileName() { return input_file_name_; }
    unsigned int ReadInputFile();
private:
    std::string input_file_name_;
};
