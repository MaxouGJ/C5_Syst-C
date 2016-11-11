#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int somme(int tab[], int len){
  int somme = 0;
  int i=0;
  for(i=0; i<len; i++){
    somme = somme + tab[i];
  }
  return somme;
}

int main(int argc, char *argv[]){
  int n = atoi(argv[1]);
  int tab[n];
  int i;
  char res[8];
  for(i=0; i<n; i++){
    fgets(res, 8, stdin);
    tab[i] = atoi(res);
  }

  int j=0;
  int tab1[n/2];
  for(j=0; j<n/2; j++){
    tab1[j] = tab[j];
  }
  int k=0;
  int tab2[n/2+1];
  for(k=n/2; k<n; k++){
    tab2[k-n/2] = tab[k];
  }
  
  int s = 0;
  pid_t pid1, pid2, fils1, fils2;
  pid1 = fork();
  switch(pid1){
  case 0:
    exit(somme(tab1, n/2));
  default:
    pid2 = fork();
    if(pid2 == 0)
      if(n%2 == 0)
	exit(somme(tab2, n/2));
      else
	exit(somme(tab2, n/2+1));
  }
  waitpid(pid1, &fils1, 0);
  waitpid(pid2, &fils2, 0);

  s=WEXITSTATUS(fils1)+WEXITSTATUS(fils2);
   
  printf("Somme : %d\n", s); 
}
