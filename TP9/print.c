#include <stdio.h>

int main(int argc, char *argv[]){
  if(argc > 2){
    int i;
    for(i=0; i<atoi(argv[2]); i++){
      printf("%d\n", atoi(argv[1]));
    }
  }else{
    printf("Erreur arguments manquants");
  }
}
