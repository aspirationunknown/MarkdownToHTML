#include "markdowntohtml.h"

int run_application(std::vector<std::string>& args, unsigned int num_args_expected) {
    if (args.size() != num_args_expected) {
        return 1;
    }
    return 0;
}
