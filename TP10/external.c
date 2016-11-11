#include "mysh.h"

/* _____________________________________________________ */
// Essaye d'exécuter la commande externe 'argv[0]' avec
// les arguments spécifiés dans 'argv'.
// Renvoie 1 en cas d'échec, 0 si la commande est lancée
// en arrière-plan, et le code retour de la commande sinon.
int execute_command_external(int argc, char** argv) {
  int ap = 0;//boolean arriere plan
  if(strcmp(argv[argc-1], "&") == 0){
    ap = 1;
    argv[argc-1] = NULL;
  }
  pid_t pid, fils;
  pid = fork();
  if(pid == 0){
    int retour = execvp(argv[0], argv);
    if(retour == -1){
      perror("Impossible d'exécuter la commande");
      exit(1);
    }
  }else{
    if(ap){
      printf("pid : %d\n", pid);
      return 0;
    }else{
      waitpid(pid, &fils, 0);
      return WEXITSTATUS(fils);
    }
  }return 0;//Jamais atteint, pour la compilation
}
