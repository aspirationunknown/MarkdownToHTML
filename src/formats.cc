#include "formats.h"

Title::Title(std::string text): text_(text) {}

std::string Title::GetText() {
    return text_;
}

Header::Header(std::string text, unsigned short lvl): text_(text), lvl_(lvl) {}

std::string Header::GetText() {
    return text_;
}

unsigned short Header::GetLevel() {
    return lvl_;
}

BoldText::BoldText(std::string text): text_(text) {}

std::string BoldText::GetText() {
    return text_;
}

ItalicText::ItalicText(std::string text): text_(text) {}

std::string ItalicText::GetText() {
    return text_;
}

BoldItalicText::BoldItalicText(std::string text): text_(text) {}

std::string BoldItalicText::GetText() {
    return text_;
}

PlainText::PlainText(std::string text): text_(text) {}

std::string PlainText::GetText() {
    return text_;
}

BlockQuote::BlockQuote(std::string text): text_(text) {}

std::string BlockQuote::GetText() {
    return text_;
}

OrderedList::OrderedList(std::string text, unsigned short rank): text_(text), rank_(rank) {}

std::string OrderedList::GetText() {
    return text_;
}

unsigned short OrderedList::GetRank() {
    return rank_;
}

UnorderedList::UnorderedList(std::string text): text_(text) {}

std::string UnorderedList::GetText() {
    return text_;
}

InlineCode::InlineCode(std::string text): text_(text) {}

std::string InlineCode::GetText() {
    return text_;
}

CodeBlock::CodeBlock(std::string text): text_(text) {}

std::string CodeBlock::GetText() {
    return text_;
}

Hyperlink::Hyperlink(std::string text, std::string url): text_(text), url_(url) {}

std::string Hyperlink::GetText() {
    return text_;
}

std::string Hyperlink::GetUrl() {
    return url_;
}

Image::Image(std::string alt, std::string url): alt_(alt), url_(url) {}

std::string Image::GetAlt() {
    return alt_;
}

std::string Image::GetUrl() {
    return url_;
}
