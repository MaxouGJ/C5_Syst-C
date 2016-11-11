#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "mysh.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int execute_command_redirect(int argc, char **argv){
  int f;
  pid_t pid;
  int entree = 0;
  int sortie = 0;
  int erreur = 0;

  //Test dans quel cas travaille-t-on entrée ou sortie ou erreur
  if(strcmp(argv[0], "<") == 0)
     entree = 1;
  if(strcmp(argv[0], ">") == 0)
     sortie = 1;
  if(strcmp(argv[0], ">2") == 0)
     erreur = 1;

  if(argc < 3){
    fprintf(stderr, "Usage : %s FILE TEXT\n", argv[0]);
    return 1;
  }
  if((pid = fork()) == -1) {
    fprintf(stderr, "mysh : fork a échoué");
    return 1;
  }else if(pid == 0){
    //Si on travaille sur l'entrée
    if (entree ==1){
      if((f = open(argv[1], O_RDONLY)) == -1){
	fprintf(stderr, "mysh : impossible d'ouvrir le fichier %s\n", argv[1]);
	return 1;
      }if(dup2(f, STDIN_FILENO) == -1){
	//fprintf(stderr, "mysh : dup2 in a échoué");
	return 1;
      }
    }
    //Si on travaille sur la sortie
    else if(sortie ==1){
      if((f = open(argv[1], O_WRONLY|O_APPEND|O_CREAT, S_IRUSR|S_IWUSR)) == -1){
	fprintf(stderr, "mysh : impossible d'ouvrir le fichier %s\n", argv[1]);
	return 1;
      }if(dup2(f, STDOUT_FILENO) == -1){
	//fprintf(stderr, "mysh : dup2 out a échoué");
	return 1;
      }
    }
    //Si on travaille sur la sortie d'erreur
    else if(erreur == 1){
      if((f = open(argv[1], O_WRONLY|O_APPEND|O_CREAT, S_IRUSR|S_IWUSR)) == -1){
	fprintf(stderr, "mysh : impossible d'ouvrir le fichier %s\n", argv[1]);
	return 1;
      }if(dup2(f, STDERR_FILENO) == -1){
	//fprintf(stderr, "mysh : dup2 out a échoué");
	return 1;
      }
    }
    //Execution de la commande
    if(execvp(argv[2], argv+2) == -1){
      fprintf(stderr, "%s : commande invalide\n", argv[2]);
      return 1;
    }
    //On mange les deux premiers argv
    
    
    return 0;
  }else {
    int exitstat;
    if (waitpid(pid, &exitstat, 0) != pid) {
      fprintf(stderr, "mysh: waitpid a echoue.\n");
      return 1;
    }
    return WEXITSTATUS(exitstat);
  }
}
