#include <iostream>

#include "markdowntohtml.h"

int main(int argc, char* argv[]) {
    constexpr auto Num_Args_Expected = 1u;

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }
    std::vector<std::string> args{argv[1]};

    return run_application(args, Num_Args_Expected);
}
