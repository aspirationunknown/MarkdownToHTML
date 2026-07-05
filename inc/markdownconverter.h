#include "converter.h"

class MarkdownConverter : public Converter {
public:
    MarkdownConverter() = delete;
    MarkdownConverter(std::string input_file_name);
    ~MarkdownConverter();

private:
    std::string file_extension_{"md"};
};
