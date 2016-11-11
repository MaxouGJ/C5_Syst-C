#include "mytouch.h"

int main(int argc, char *argv[]){
  char *pathname = argv[argc-1];
  char *option;
  char *time;

  if(argc > 2){
    option = argv[1];
  }
  
  int fd = access(pathname, R_OK|W_OK);
  if(fd == 0){
    printf("Fichier déjà créé\n");
    
    struct stat infos;
    struct timespec times[2];
    stat(pathname, &infos);

    struct tm tm;
    time_t t = NULL;
    if(strcmp(time, "") != 0){
      strptime(time, "%Y-%m-%d %H:%M:%S", &tm);
      t = mktime(&tm);
    }
  
    if(strcmp(option, "-m") == 0){
      times[0].tv_sec = infos.st_atim.tv_sec;
      if(t != NULL){
	times[1].tv_sec = t;
      }else{
	times[1].tv_sec = UTIME_NOW;
      }
    }else if(strcmp(option, "-a") == 0){
      if(t != NULL){
	times[0].tv_sec = t;
      }else{
	times[0].tv_sec = UTIME_NOW;
      }
      times[1].tv_sec= infos.st_mtim.tv_sec;
    }else if(strcmp(option, "-am") == 0){
      if(t != NULL){
	times[0].tv_sec = t;
	times[1].tv_sec = t;
      }else{
	times[0].tv_sec = UTIME_NOW;
	times[1].tv_sec = UTIME_NOW;
      }
    }

    utimensat(AT_FDCWD, pathname, times, 0);
    close(fd);
  }else{
    printf("Création du fichier\n");
    fd=creat(pathname, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH); 
    futimens(fd, NULL);
    close(fd);
  }
}
