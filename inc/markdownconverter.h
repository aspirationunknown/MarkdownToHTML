#include "converter.h"

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
};
