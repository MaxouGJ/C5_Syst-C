#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
  if(argc < 2){
    perror("Argument manquant");
    exit(1);
  }
  char *pathname = strcat(get_curent_dir_name(), "/");
  pathname = strcat(pathname, argv[1]);
  printf(pathname);
  /*  if(execl("ls", "ls", pathname, NULL) == -1){
    perror(pathname);
    exit(1);
  }
  printf("Démarrage copie de %s dans backup...\n", pathname);
  if(execl("cp", "cp", "-r", pathname, "backup", NULL) == -1){
    perror("Erreur de copie");
    exit(1);
    }printf("Copie terminée");*/
}
