#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  pid_t pid;
  pid = fork();
  if(pid == 0){
    execl("./print", "print", "10", "200", NULL);
  }else{
    execl("./print", "print", "22", "200", NULL);
  }
}
