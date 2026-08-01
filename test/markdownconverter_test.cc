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
    std::vector<StyledText> expected_vec{{"The Special Input", TextStyleState::Bold},
                                         {".", TextStyleState::NoStyle}};

    std::vector<StyledText> result_vec {mc.ProcessInputLine(line)};

    EXPECT_EQ(result_vec.size(), expected_vec.size());
    for(unsigned int i = 0; i < result_vec.size(); ++i) {
        EXPECT_EQ(result_vec[i], expected_vec[i]);
    }
}

TEST(MarkdownConverterTest, ParseInputBold) {
    std::string input_file_name{"FakeFileName.md"};
    MarkdownConverter mc{input_file_name};
    std::string input_line{"**Bold words**"};
    std::vector<StyledText> expected_vec{{"Bold words", TextStyleState::Bold}};
    std::vector<StyledText> result_vec{};

    mc.ParseInput(input_line, result_vec);
    EXPECT_EQ(result_vec.size(), expected_vec.size());
    for(unsigned int i = 0; i < result_vec.size(); ++i) {
        EXPECT_EQ(result_vec[i], expected_vec[i]);
    }
}
