#include <gtest/gtest.h>

#include "markdowntohtml.h"

TEST(MarkdownToHTMLTest, CommandLineArgs) {
    std::vector<std::string> args = {"testfile.name"};

    EXPECT_EQ(run_application(args), 0);
}
