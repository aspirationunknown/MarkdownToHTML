#ifndef MARKDOWN_CONVERTER_H
#define MARKDOWN_CONVERTER_H

#include <string>

#include "converter.h"

class MarkdownConverter : public Converter {
public:
  MarkdownConverter() = delete;
  MarkdownConverter(const std::string &output_file_name);
  ~MarkdownConverter() override = default;
  MarkdownConverter(const MarkdownConverter &) = delete;
  MarkdownConverter(MarkdownConverter &&) = delete;
  MarkdownConverter &operator=(const MarkdownConverter &) = delete;
  MarkdownConverter &&operator=(MarkdownConverter &&) = delete;
};

#endif // MARKDOWN_CONVERTER_H
