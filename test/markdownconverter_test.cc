#include <gtest/gtest.h>

#include "markdownconverter.h"

TEST(MarkdownConverterTest, InputFile) {
    std::string input_file_name{"input.file"};
    MarkdownConverter mc{input_file_name};
    MarkdownConverter mc_no_args{};

    EXPECT_EQ(mc.GetInputFileName(), input_file_name);
    EXPECT_EQ(mc_no_args.GetInputFileName(), "");
}

TEST(MarkdownConverterTest, ReadInputFile) {
    std::string input_file_name{"data/SimpleInputFile.md"};
    MarkdownConverter mc{input_file_name};

    EXPECT_EQ(mc.ReadInputFile(), InputFileStatus::Ok);
}

TEST(MarkdownConverterTest, ReadInputFileFailureToOpen) {
    std::string input_file_name{"data/FileDoesNotExist.md"};
    MarkdownConverter mc{input_file_name};

    EXPECT_EQ(mc.ReadInputFile(), InputFileStatus::Failed_To_Open);
}
