#include <stdio.h>
#include <stdlib.h>
#include "mysh.h"

/* _____________________________________________________ */
// Synopsis:  exit [STATUS]
int execute_command_exit(int argc, char** argv) {
    if (argc == 1)
        exit(0);
    if (argc > 2) {
        fprintf(stderr, "exit: Un argument au maximum.\n");
        return 1;
    }
    char* endptr;  // Indiquera où 'strlol' s'est arrêté.
    int val = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0') {
        fprintf(stderr, "exit: Argument doit etre un entier.\n");
        return 1;
    }
    if (val < 0) {
        fprintf(stderr, "exit: Argument doit etre >= 0.\n");
        return 1;
    }
    exit(val);
}

/* _____________________________________________________ */
// Synopsis:  status
int execute_command_status(int argc, char** argv) {
  printf("%d\n", status);
  return 0;
}

/* _____________________________________________________ */
// Synopsis:  cd [DIRECTORY]
int execute_command_cd(int argc, char** argv) {
  int retour;
  if(argc > 1){
    if(strcmp(argv[1], "-") == 0){
      retour = chdir("..");
      //setenv("PWD", "", 1);
    }else{     
      retour = chdir(argv[1]);
      char *dossier = strcat(getenv("PWD"), "/");
      dossier = strcat(dossier, argv[1]);
      setenv("PWD", dossier, 1);
    }
  }
  else{
    retour = chdir(getenv("HOME"));
    setenv("PWD", getenv("HOME"), 1);
  }
  return retour;
}

/* _____________________________________________________ */
// Synopsis:  pwd
int execute_command_pwd(int argc, char** argv) {
  printf("%s\n", getenv("PWD"));
  return 0;
}
