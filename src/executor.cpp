#include "shell.hpp"
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>
#include <vector>
#include <sys/wait.h>

void executeCommand(const std::vector<std::string> &args){
  if (args.empty()) {
    return;
  }
  if (args[0]=="cd") {
    const char* path=(args.size()>1)?args[1].c_str():getenv("HOME");
    if(chdir(path)!=0) {
      perror("duyShell: cd");
    }
    return;
  }
  std::vector<char*>c_args;
  for (const auto& arg : args) {
    c_args.push_back(const_cast<char*>(arg.c_str()));
  }
  c_args.push_back(nullptr);
  pid_t pid=fork();
  if (pid<0) {
    perror("duyShell: gagal forking");
  }else if (pid==0) {
    if (execvp(c_args[0],c_args.data())==-1) {
      perror("duyShell");
    }
    exit(EXIT_FAILURE);
  }else {
    int status;
    waitpid(pid,&status,0);
  }
}
