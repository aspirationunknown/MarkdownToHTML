#include <fstream>
#include <string>

enum class InputFileStatus { Ok = 0, Failed_To_Open };

class MarkdownConverter {
public:
    MarkdownConverter();
    MarkdownConverter(std::string input_file_name);
    ~MarkdownConverter();

    const std::string GetInputFileName() { return input_file_name_; }
    InputFileStatus ReadInputFile();
private:
    std::string input_file_name_{};
    std::ifstream input_file_;
};
