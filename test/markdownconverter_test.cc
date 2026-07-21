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

TEST(MarkdownConverterTest, GetFileBaseName) {
    std::string expected_base_name{"SimpleInputFile"};
    std::string input_file_name{"data/SimpleInputFile.md"};
    MarkdownConverter mc{input_file_name};

    EXPECT_EQ(mc.GetInputFileBaseName(), expected_base_name);
}

TEST(MarkdownConverterTest, ProcessInputBold) {
    std::string input_file_name{"data/SimpleInputFile.md"};
    MarkdownConverter mc{input_file_name};
    std::string line{"**The Special Input**."};
    std::vector<StyledText> result_vec{{"The", TextStyleState::Bold}, {" ", TextStyleState::NoStyle},
                                       {"Special", TextStyleState::Bold}, {" ", TextStyleState::NoStyle},
                                       {"Input", TextStyleState::Bold}, {".", TextStyleState::NoStyle}};

    std::vector<StyledText> st_vec {mc.ProcessInputLine(line)};

    EXPECT_EQ(st_vec.size(), result_vec.size());
    for(unsigned int i = 0; i < st_vec.size(); ++i) {
        EXPECT_EQ(st_vec[i], result_vec[i]);
    }
}
