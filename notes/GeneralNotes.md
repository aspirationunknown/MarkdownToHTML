# General Notes

## Notes For The Present
- Have output files use the same base name as input file, just with a *.html extension
- Add exception handling for opening input and output files
- Take notes for mapping markdown tags to html tags/attributes
- Consider making class that contains a string and an enum class instance that encodes the formatting (bold, italic, or both)
- Start parsing the input file
- Start thinking about how the HTML output will be generated
- Start refactoring MarkdownConverter class such that there is a Converter base class that contains the common functionality and sub-classes for the different input types
- Start creating the base Writer class to be sub-classed for the different types of output

### Intermediate Representation
- Bold - Enum with value of Bold
- Italics - Enum with value of Italic
- Bold + Italics - Enum with value of BoldItalic
- Normal Text - Enum with value of NoStyle
- Block Quote
- Unordered List
- Ordered List
- Inline Code
- Code Block
- Horizontal Rule
- Link
- Image

## Notes For The Future
- Have separate classes for each type of input file
- Have separate classes for each type of output file
- Consider having optional specified output file base names (extension will be file type specific)
- Consider using an Abstract Syntax Tree (AST) as an intermediate representation that can then be converted into the target format
- Consider using Visitor Pattern for tree traversals
-

## Mermaid Diagram Example
```mermaid
graph TD
  A[Start] --> B{Decision}
  B --> |Yes| C[Finish]
  B --> |No| D[Alternate]
```
