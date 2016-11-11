#include <stdio.h>
#include "fillib.h"

int main(int argc, char *argv[]){
  if(argv[1] != NULL){
    if(strcmp(argv[1],"-b") == 0){
      printf("b");
      if(argv[2] != NULL){
	FILE *file = fopen(argv[2], "r");
	copyLines(file, stdout);
      }
    }
    else{
      FILE *file = fopen(argv[1], "r");
      copy(file, stdout);
    }
  }
  return 0;
}
