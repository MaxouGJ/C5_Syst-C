#include <stdio.h>
#include "fillib.h"

int main(int argc, char *argv[]){
  if(argv[1] != NULL && argv[2] != NULL){
    FILE * fsrc = fopen(argv[1], "r");
    FILE *fdst = fopen(argv[2], "w+");
    copy(fsrc, fdst);
  }
  return 0;
}
