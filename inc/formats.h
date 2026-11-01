#ifndef FORMATS_H
#define FORMATS_H

#include <string>
#include <variant>

struct Title {
  Title() = delete;
  Title(std::string text);
  ~Title() = default;
  Title(const Title &) = default;
  Title &operator=(const Title &) = default;
  Title(Title &&) = default;
  Title &operator=(Title &&) = default;

  std::string GetText();

private:
  std::string text_;
};

struct Header {
public:
  Header() = delete;
  Header(std::string text, unsigned short lvl);
  ~Header() = default;
  Header(const Header &) = default;
  Header &operator=(const Header &) = default;
  Header(Header &&) = default;
  Header &operator=(Header &&) = default;

  [[nodiscard]]
  unsigned short GetLevel() const;
  std::string GetText();

private:
  unsigned short lvl_;
  std::string text_;
};

struct BoldText {
  BoldText() = delete;
  BoldText(std::string text);
  ~BoldText() = default;
  BoldText(const BoldText &) = default;
  BoldText &operator=(const BoldText &) = default;
  BoldText(BoldText &&) = default;
  BoldText &operator=(BoldText &&) = default;

  std::string GetText();

private:
  std::string text_;
};

struct ItalicText {
  ItalicText() = delete;
  ItalicText(std::string text);
  ~ItalicText() = default;
  ItalicText(const ItalicText &) = default;
  ItalicText &operator=(const ItalicText &) = default;
  ItalicText(ItalicText &&) = default;
  ItalicText &operator=(ItalicText &&) = default;

  std::string GetText();

private:
  std::string text_;
};

struct BoldItalicText {
  BoldItalicText() = delete;
  BoldItalicText(std::string text);
  ~BoldItalicText() = default;
  BoldItalicText(const BoldItalicText &) = default;
  BoldItalicText &operator=(const BoldItalicText &) = default;
  BoldItalicText(BoldItalicText &&) = default;
  BoldItalicText &operator=(BoldItalicText &&) = default;

  std::string GetText();

private:
  std::string text_;
};

struct PlainText {
  PlainText() = delete;
  PlainText(std::string text);
  ~PlainText() = default;
  PlainText(const PlainText &) = default;
  PlainText &operator=(const PlainText &) = default;
  PlainText(PlainText &&) = default;
  PlainText &operator=(PlainText &&) = default;

  std::string GetText();

private:
  std::string text_;
};

struct BlockQuote {
  BlockQuote() = delete;
  BlockQuote(std::string text);
  ~BlockQuote() = default;
  BlockQuote(const BlockQuote &) = default;
  BlockQuote &operator=(const BlockQuote &) = default;
  BlockQuote(BlockQuote &&) = default;
  BlockQuote &operator=(BlockQuote &&) = default;

  std::string GetText();

private:
  std::string text_;
};

struct OrderedList {
public:
  OrderedList() = delete;
  OrderedList(std::string text, unsigned short rank);
  ~OrderedList() = default;
  OrderedList(const OrderedList &) = default;
  OrderedList &operator=(const OrderedList &) = default;
  OrderedList(OrderedList &&) = default;
  OrderedList &operator=(OrderedList &&) = default;

  [[nodiscard]]
  unsigned short GetRank() const;
  std::string GetText();

private:
  unsigned short rank_;
  std::string text_;
};

struct UnorderedList {
  UnorderedList() = delete;
  UnorderedList(std::string text);
  ~UnorderedList() = default;
  UnorderedList(const UnorderedList &) = default;
  UnorderedList &operator=(const UnorderedList &) = default;
  UnorderedList(UnorderedList &&) = default;
  UnorderedList &operator=(UnorderedList &&) = default;

  std::string GetText();

private:
  std::string text_;
};

struct InlineCode {
  InlineCode() = delete;
  InlineCode(std::string text);
  ~InlineCode() = default;
  InlineCode(const InlineCode &) = default;
  InlineCode &operator=(const InlineCode &) = default;
  InlineCode(InlineCode &&) = default;
  InlineCode &operator=(InlineCode &&) = default;

  std::string GetText();

private:
  std::string text_;
};

struct CodeBlock {
  CodeBlock() = delete;
  CodeBlock(std::string text);
  ~CodeBlock() = default;
  CodeBlock(const CodeBlock &) = default;
  CodeBlock &operator=(const CodeBlock &) = default;
  CodeBlock(CodeBlock &&) = default;
  CodeBlock &operator=(CodeBlock &&) = default;

  std::string GetText();

private:
  std::string text_;
};

struct HorizontalRule {
  HorizontalRule() = default;
  ~HorizontalRule() = default;
  HorizontalRule(const HorizontalRule &) = default;
  HorizontalRule &operator=(const HorizontalRule &) = default;
  HorizontalRule(HorizontalRule &&) = default;
  HorizontalRule &operator=(HorizontalRule &&) = default;
};

struct Url {
  std::string url;
};

struct Hyperlink {
  Hyperlink() = delete;
  Hyperlink(std::string text, Url url);
  ~Hyperlink() = default;
  Hyperlink(const Hyperlink &) = default;
  Hyperlink &operator=(const Hyperlink &) = default;
  Hyperlink(Hyperlink &&) = default;
  Hyperlink &operator=(Hyperlink &&) = default;

  std::string GetText();
  [[nodiscard]]
  std::string GetUrl() const;

private:
  std::string text_;
  Url url_;
};

struct Image {
  Image() = delete;
  Image(std::string alt_text, Url url);
  ~Image() = default;
  Image(const Image &) = default;
  Image &operator=(const Image &) = default;
  Image(Image &&) = default;
  Image &operator=(Image &&) = default;

  std::string GetAlt();
  [[nodiscard]]
  std::string GetUrl() const;

private:
  std::string alt_;
  Url url_;
};

using Formats = std::variant<std::monostate, Title, Header, BoldText,
                             ItalicText, BoldItalicText, PlainText, BlockQuote,
                             UnorderedList, OrderedList, InlineCode, CodeBlock,
                             HorizontalRule, Hyperlink, Image>;

#endif // FORMATS_H
