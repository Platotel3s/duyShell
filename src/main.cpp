#include "shell.hpp"
#include <csignal>
#include <filesystem>
#include <iostream>
#include <string>
int main (int argc, char *argv[]) {
  std::signal(SIGINT,SIG_IGN);
  std::string input;
  while (true) {
    std::string cwd=std::filesystem::current_path().filename().string();
    std::cout<<"\033[1;32mduyShell\033[0m ~> \033[1;34m"<<cwd<<"\033[0m$ ";
    if (!std::getline(std::cin,input)) {
      std::cout<<"\n";
      break;
    }
    if (input=="exit") {
      break;
    }
    auto args=parseInput(input);
    executeCommand(args);
  }
  return 0;
}
