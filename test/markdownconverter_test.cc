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
    constexpr auto File_Opened_Successfully = 0u;
    std::string input_file_name{"data/SimpleInputFile.md"};
    MarkdownConverter mc{input_file_name};

    EXPECT_EQ(mc.ReadInputFile(), File_Opened_Successfully);
}

TEST(MarkdownConverterTest, ReadInputFileFailureToOpen) {
    constexpr auto File_Failed_To_Open = 1u;
    std::string input_file_name{"data/FileDoesNotExist.md"};
    MarkdownConverter mc{input_file_name};

    EXPECT_EQ(mc.ReadInputFile(), File_Failed_To_Open);
}
