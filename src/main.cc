#include <iostream>

#include "markdowntohtml.h"

int main(int argc, char *argv[]) {
  constexpr auto Num_Args_Expected = 1;
  const std::span<char *> args{argv, static_cast<std::size_t>(argc)};

  if (argc != Num_Args_Expected + 1) {
    std::cerr << "Usage: " << argv[0] << " <input_file>\n";
    return 1;
  }

  return run_application(args);
}
