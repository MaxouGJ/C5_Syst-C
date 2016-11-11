#include "myio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define _READ 1 //Fichier en mode lecture
#define _WRITE 2 //Fichier en mode écriture
#define _NOBUF 4 //On n'utilise pas de buffer
#define _EOF 8 //FIn du fichier atteinte
#define _ERROR 16 //Une erreur s'est produite

MY_FILE _files[MY_FOPEN_MAX] = {
  {0, _READ, MY_NULL, MY_NULL, 0},
  {1, _WRITE, MY_NULL, MY_NULL, 0},
  {2, _WRITE | _NOBUF, MY_NULL, MY_NULL, 0}
};

MY_FILE *mystdin = _files; //ou &_files[0]
MY_FILE *mystdout = _files+1; //ou &_files[1]
MY_FILE *mystderr = _files+2; //ou &_files[2]

MY_FILE* myfopen(const char *path, const char *mode){
  int file_descriptor;
  int flags;
  int rights;
  MY_FILE *file;
  int i;

  for(i=3; i<MY_FOPEN_MAX; i++){
    if(_files[i].flags == 0){
      file = &_files[i];
    }
  }
  
  if(mode == "r"){
    flags = O_RDONLY;
    rights = S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH;
  }else if(mode == "w"){
    flags = O_WRONLY|O_CREAT|O_TRUNC;
    rights = S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH;
  }else if(mode == "a"){
    flags = O_APPEND|O_CREAT|O_TRUNC;
    rights = S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH;
  }else{
    return MY_NULL;
  }
  
  file_descriptor  = open(path, flags, rights);

  if(file_descriptor == -1){
    perror(path);
    return MY_NULL;
  }else{
    file->fd = file_descriptor;
    file->flags = flags;

    return file;
  } 
}

int myfclose(MY_FILE *fp){
  int fclose;
  fclose = close(fp->fd);
  if(close == 0){
    fp->flags = 0;
    free(fp->buf);
    return 0;
  }
  else return MY_EOF;
}

int _fillbuffer(MY_FILE *fp){
  ssize_t lus;
  if(fp->buf == MY_NULL){
    if(fp->flags&_NOBUF == 0){
      char buf[MY_BUFSIZE];
      fp->buf = buf;
      fp->flags = _NOBUF;
      fp->count = MY_BUFSIZE;
    }else{
      fp->buf = malloc(sizeof(char));
      fp->count = sizeof(char);
    }
  }
  lus = read(fp->fd, fp->buf, fp->count);
  if(lus == -1)
    return MY_EOF;

  fp->count = fp->count - lus;
  return fp->buf[0];
}

int _flushbuffer(int c, MY_FILE *fp){
  if(fp->buf == MY_NULL){
    if(fp->flags&_NOBUF == 0){
      char buf[MY_BUFSIZE];
      fp->buf = buf;
      fp->flags = _NOBUF;
      fp->count = MY_BUFSIZE;
    }else{
      fp->buf = malloc(sizeof(char));
      fp->count = sizeof(char);
    }
  }
  if(c == MY_EOF)
    return MY_EOF;

  write(fp->fd, c, (fp->count + 1)) ;
  write(fp->fd, fp->buf, (fp->count + 1)) ;
  fp->buf = MY_NULL;
  fp->count = MY_NULL;
  return c;
}

int main(){
  MY_FILE * file;
  file = myfopen("banana.txt", "r");
  printf("%d", _fillbuffer(file));
  printf("%d", _flushbuffer(2, file));
  //myfclose(file);
}
