#include <stdio.h>

int copy(FILE *fsrc, FILE *fdst){
  //fopen(fsrc, "r");
  //fopen(fdst, "w+");
  char[64] text = fgets(text, 64, fsrc);
  while(text != NULL){
    fput(text, fdst);
    text = fgets(fsrc);
  }
}
