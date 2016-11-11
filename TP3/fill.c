#include <stdio.h>

int main(int argc, char* argv[]){ 
  if(argc != 3){
    printf("Erreur d'arguments");
  }
  else{
    FILE *file;
    file = fopen(argv[1], "a");
    if(file == NULL){
      file = fopen(argv[1],"a");
    }
    int i=0;
    int n=atoi(argv[2]);
    for(i; i<n; i++){
      fputs("banaaaana !!!\n", file);
    }
    //fclose(argv[1]);
  }
  //return 0;
}
