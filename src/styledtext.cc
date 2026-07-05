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

StyledText::StyledText(const StyledText& styled_text) {
    this->value = styled_text.value;
    this->style = styled_text.style;
}

StyledText& StyledText::operator=(const StyledText& styled_text) {
    if (this != &styled_text) {
        this->value = styled_text.value;
        this->style = styled_text.style;
    }
    return *this;
}
