#include <cstdlib>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <format>
#include <iostream>

auto get_ps1(unsigned int code) {
  if (code != 0) {
    return "[" + std::to_string(code) + "] > ";
  } else {
    return std::string("[] > ");
  }
}

int main(void) {
  auto exit_code = 0;

  while (true) {
    std::cout << get_ps1(exit_code);

    std::string cmd;
    std::getline(std::cin, cmd);

    if (!cmd.empty()) {
      if (cmd.compare("exit") == 0) {
        return EXIT_SUCCESS;
      }
      exit_code = std::system(cmd.c_str());
    }
    
    std::cout << std::endl;
  }
  
  return EXIT_SUCCESS;
}
