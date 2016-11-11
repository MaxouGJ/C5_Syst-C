#define DICTENT_KEYLENGTH 15
#define DICTENT_VALLENGTH 63
#define DICT_INITSIZE 128
#define DICT_NOTFOUND -1

typedef struct{
  char *key;
  char *val;
}*dictent_t;

typedef struct{
  dictent_t *elems [DICT_INITSIZE];
  int size;
}*dict_t;
