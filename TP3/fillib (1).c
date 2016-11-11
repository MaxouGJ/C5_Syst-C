#include <stdio.h>

int copy(FILE *fsrc, FILE *fdst){
  char text [64];
  while(fgets(text, 64, fsrc) != NULL)
    fputs(text, fdst);
  return 0;
}

int nbLines(FILE *file){
  int l=0;
  char c[64];
  while(fgets(c, 64, file) != NULL){
    int i=0;
    for(i; i<strlen(c); i++){
      if(c[i] == '\n'){
	l ++;
      }
    }
  }
  return l;
}

int copyLines(FILE *fsrc, FILE *fdst){
  int l=0;
  char c[64];
  fprintf(fdst,"%d ", 1);
  while(fgets(c, 64, fsrc) != NULL){
    int i=0;
    if(strlen(c) != 1){
      if(c[strlen(c)-1] == '\n'){
	  l ++;
	  fprintf(fdst,"%d ", l);
      }
    }
    fputs(c, fdst);
  }
}

/*int main(int argc, char *argv[]){
  FILE *fsrc = fopen(argv[1], "r");
  FILE *fdst = fopen(argv[2], "w+");
  copyLines(fsrc, fdst);
}
*/
