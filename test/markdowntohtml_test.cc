#include <gtest/gtest.h>

#include <array>
#include <span>

#include "markdowntohtml.h"

TEST(MarkdownToHTMLTest, CommandLineArgs) {
  constexpr std::size_t filename_size = 14;
  std::array<char, filename_size> filename = {"testfile.name"};
  std::array<char *, 1> argv = {filename.data()};
  const std::span<char *> args{argv};

  EXPECT_EQ(run_application(args), 0);
}
