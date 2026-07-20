#include <fstream>
#include <string>

enum class InputFileStatus { Ok = 0, Failed_To_Open };

class Converter {
public:
    Converter(std::string input_file_name);
    virtual ~Converter();

    virtual InputFileStatus ReadInputFile();
    std::string GetInputFileBaseName();

private:
    Converter();

protected:
    std::string input_file_name_{};
    std::ifstream input_file_;
};
