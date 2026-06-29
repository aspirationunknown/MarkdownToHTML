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
-  

## Notes For The Future
- Have separate classes for each type of input file
- Have separate classes for each type of output file
- Consider having optional specified output file base names (extension will be file type specific)
-
