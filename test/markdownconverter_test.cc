#include <gtest/gtest.h>

#include "markdownconverter.h"

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
