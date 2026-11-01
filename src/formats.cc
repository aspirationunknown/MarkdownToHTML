#include "formats.h"

Title::Title(std::string text) : text_(std::move(text)) {}

std::string Title::GetText() { return text_; }

Header::Header(std::string text, unsigned short lvl)
    : text_(std::move(text)), lvl_(lvl) {}

std::string Header::GetText() { return text_; }

unsigned short Header::GetLevel() const { return lvl_; }

BoldText::BoldText(std::string text) : text_(std::move(text)) {}

std::string BoldText::GetText() { return text_; }

ItalicText::ItalicText(std::string text) : text_(std::move(text)) {}

std::string ItalicText::GetText() { return text_; }

BoldItalicText::BoldItalicText(std::string text) : text_(std::move(text)) {}

std::string BoldItalicText::GetText() { return text_; }

PlainText::PlainText(std::string text) : text_(std::move(text)) {}

std::string PlainText::GetText() { return text_; }

BlockQuote::BlockQuote(std::string text) : text_(std::move(text)) {}

std::string BlockQuote::GetText() { return text_; }

OrderedList::OrderedList(std::string text, unsigned short rank)
    : text_(std::move(text)), rank_(rank) {}

std::string OrderedList::GetText() { return text_; }

unsigned short OrderedList::GetRank() const { return rank_; }

UnorderedList::UnorderedList(std::string text) : text_(std::move(text)) {}

std::string UnorderedList::GetText() { return text_; }

InlineCode::InlineCode(std::string text) : text_(std::move(text)) {}

std::string InlineCode::GetText() { return text_; }

CodeBlock::CodeBlock(std::string text) : text_(std::move(text)) {}

std::string CodeBlock::GetText() { return text_; }

Hyperlink::Hyperlink(std::string text, Url url)
    : text_(std::move(text)), url_(std::move(url)) {}

std::string Hyperlink::GetText() { return text_; }

std::string Hyperlink::GetUrl() const { return url_.url; }

Image::Image(std::string alt_text, Url url)
    : alt_(std::move(alt_text)), url_(std::move(url)) {}

std::string Image::GetAlt() { return alt_; }

std::string Image::GetUrl() const { return url_.url; }
