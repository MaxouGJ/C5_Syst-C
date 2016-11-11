#define MY_NULL 0
#define MY_EOF -1
#define MY_FOPEN_MAX 64
#define MY_BUFSIZE 1024

typedef struct {
  int fd; //permet d'identifier le fichier
  int flags; //permet de connaitre les droits
  unsigned char * buf; //Pointera sur un buffer pour stocker le fichier
  unsigned char * pos; //Pointeur sur la tête de lecture
  int count; //Place disponible dans le buffer
} MY_FILE;

extern MY_FILE* mystdin;
extern MY_FILE* mystdout;
extern MY_FILE* mysterr;

MY_FILE* myfopen(const char *path, const char *mode);
int myfclose(MY_FILE *fp);
int myfgetc(MY_FILE *stream);
int myfputc(int c, MY_FILE *stream);
