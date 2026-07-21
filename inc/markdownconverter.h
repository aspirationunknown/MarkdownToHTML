#include <array>
#include <vector>

#include "converter.h"
#include "styledtext.h"

class MarkdownConverter : public Converter {
public:
    MarkdownConverter() = delete;
    MarkdownConverter(std::string input_file_name);
    ~MarkdownConverter();
    MarkdownConverter(const MarkdownConverter&) = delete;
    MarkdownConverter(MarkdownConverter&&) = delete;
    MarkdownConverter& operator=(const MarkdownConverter&) = delete;
    MarkdownConverter&& operator=(MarkdownConverter&&) = delete;

    void ParseInput(std::string input_line, std::vector<StyledText>& result);
    std::vector<StyledText> ProcessInputLine(std::string input_line);
    InputFileStatus ReadInputFile() override;

private:
    std::array<std::string, ToIndex(TextStyleState::MaxEnum)> tags{"", "**|__", "*|_", "***|___"};
};
