#include <stdio.h>

int main(){
  FILE* fp;

  fp = fopen("test.txt", "r");
  if(fp == NULL)
    perror("Erreur ");
}
