#include <gtest/gtest.h>

#include "styledtext.h"

TEST(StyledTextTest, DefaultConstruction) {
    StyledText st{};
    StyledText expected{"", TextStyleState::NoStyle};

    ASSERT_EQ(st, expected);
}

TEST(StyledTextTest, CopyConstruction) {
    StyledText st{"test", TextStyleState::Bold};
    StyledText st2{st};

    ASSERT_EQ(st, st2);
}

TEST(StyledTextTest, CopyAssignment) {
    StyledText st{"test", TextStyleState::BoldItalic};
    StyledText st2 = st;

    ASSERT_EQ(st, st2);
}
