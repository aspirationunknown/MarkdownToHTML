#include <gtest/gtest.h>

#include "markdownconverter.h"

TEST(MarkdownConverterTest, InputFile) {
    std::string input_file_name = "input.file";
    MarkdownConverter mc{input_file_name};
    MarkdownConverter mc_no_args{};

    EXPECT_EQ(mc.GetInputFileName(), input_file_name);
    EXPECT_EQ(mc_no_args.GetInputFileName(), "");
}
