#include <gtest/gtest.h>

#include "markdowntohtml.h"


TEST(MarkdownToHTMLTest, BasicAssertions) {
    EXPECT_EQ(1, 1);
}

TEST(MarkdownToHTMLTest, CommandLineArgs) {
    std::vector<std::string> args = {"testfile.name"};
    EXPECT_EQ(run_application(args, args.size()), 0);
}

TEST(MarkdownConverterTest, InputFile) {
    std::string input_file_name = "input.file";
    MarkdownConverter mc{input_file_name};
    EXPECT_EQ(mc.GetInputFileName(), input_file_name);
}
