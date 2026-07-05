#include <string>

enum class TextStyleState { NoStyle, Bold, Italic, BoldItalic };

class StyledText {
public:
  StyledText();
  StyledText(std::string str);
  StyledText(std::string str, TextStyleState style);
  ~StyledText() = default;

  StyledText(const StyledText& styled_text);
  StyledText& operator=(const StyledText& styled_text);
  StyledText(StyledText&&) = delete;
  StyledText&& operator=(StyledText&&) = delete;
  friend bool operator==(const StyledText& lhs, const StyledText& rhs);

private:
  std::string value{};
  TextStyleState style{TextStyleState::NoStyle};
};
