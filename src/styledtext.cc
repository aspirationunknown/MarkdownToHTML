#include "styledtext.h"

bool operator==(const StyledText& lhs, const StyledText& rhs) {
    return (lhs.value == rhs.value) && (lhs.style == rhs.style);
}

StyledText::StyledText() {
    StyledText("", TextStyleState::NoStyle);
}

StyledText::StyledText(std::string str) {
    StyledText(str, TextStyleState::NoStyle);
}

StyledText::StyledText(std::string str, TextStyleState tss) : value(str), style(tss) {}
