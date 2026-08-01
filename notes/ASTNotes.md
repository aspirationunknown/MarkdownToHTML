# AST Notes

## Lexer/Tokenizer

- Maximal munch, take as many characters as possible in each bite.
- Whitespace should be included in the poissible values to be munched.
- Each line should have a newline at the end. 

### What are the tokens?
- Title, will be the first header 1 in the file [Is this true? Default to this implementation, but allow for an optional title provided as a command line argument to be added later]
- Header 1 to 5
- Text (Paragraph)
  - Unformatted Text
  - Bold Text
  - Italic Text
  - Bold & Italic Text
- Block Quote
- Ordered List
- Unordered List
- Inline Code
- Code Block
- Horizontal Rule
- Link
- Image

## Parser

### Thoughts
- Have the Tokenizer process the file and put the tokens in a queue
- Then have the Parser build the AST
- 

## Abstract Syntax Tree
- Use a Node base class
- Derived Title, Header, Unformatted Text, Bold Text, Italic Text, Bold & Italic Text, Block Quote, Ordered List, Unordered List, Inline Code, Code Block, Horizontal Rule, Link, Image classes

## Output/Translator
