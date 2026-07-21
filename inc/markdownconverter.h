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

    InputFileStatus ReadInputFile() override;
    std::vector<StyledText> ProcessInputLine(std::string input_line);
};
