#include <iostream>
#include <system_error>

#include "markdowntohtml.h"
#include "tokenizer.h"
#include "tokenqueue.h"

int run_application(std::vector<std::string>& args) {

    try {
        auto tq = std::make_shared<TokenQueue>();
        Tokenizer tokenizer(args[0], tq);
    } catch(std::system_error err) {
        std::cerr << "Failed to open file, error: " << err.what() << std::endl;
    }


    return 0;
}
