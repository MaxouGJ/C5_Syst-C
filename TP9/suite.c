#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  int n = atoi(argv[1]);
  int tab[n];
  int i;
  char *res;
  for(i=0; i<n; i++){
    fgets(res, 8, stdin);
    tab[i] = atoi(res);
  }
  
  pid_t pid;
  pid = fork();
  if(pid == 0){
    int somme = 0;
    for(i=0; i<n; i++){
      somme = somme + tab[i];
    }
    printf("somme : %d \n", somme);
  }else{
    int produit = 1;
    for(i=0; i<n; i++){
      produit = produit * tab[i];
    }
    printf("produit : %d \n", produit);
  }
  
}
