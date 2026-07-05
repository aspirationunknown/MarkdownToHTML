#include <gtest/gtest.h>

#include "styledtext.h"

TEST(StyledTextTest, Creation) {
    StyledText st{};
    StyledText expected{"", TextStyleState::NoStyle};
    ASSERT_EQ(st, expected);
}
