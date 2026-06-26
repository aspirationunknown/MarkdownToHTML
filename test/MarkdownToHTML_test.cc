#include <gtest/gtest.h>

#include "markdowntohtml.h"


TEST(MarkdownToHTMLTest, BasicAssertions) {
    EXPECT_EQ(1, 1);
}

TEST(MarkdownToHTMLTest, CommandLineArgs) {
    std::vector<std::string> args = {"testfile.name"};
    EXPECT_EQ(run_application(args), 0);
}
