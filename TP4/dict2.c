#include <stdio.h>
#include <string.h>
#include "dict2.h"

dictent_t dictentcreate(char *key, char *value){
  dictent_t ent1;
  strncpy(ent1.key, key, DICTENT_KEYLENGTH);
  strncpy(ent1.val, value, DICTENT_VALLENGTH);
  
  return ent1;
}


dict_t dictcreate(){
  dict_t d;
  d.size = 0;
  return d;
}

void dictdump(dict_t *d){
  int i=0;
  for(i; i<d->size; i++){
    fputs(d->elems[i].key, stderr);
    fputs(d->elems[i].val, stderr);
  }
}

dictent_t* dictlook(dict_t *d, char *k){
  int i=0;
  for(i; i<d->size; i++){
    if(strcmp(d->elems[i].key, k) == 0)
      return &d->elems[i];
  }
  return NULL;
}

void dictget(char *s, dict_t *d, char *k){
  int i=1;
  for(i; i<d->size; i++){
    if(strcmp(d->elems[i].key, k) == 0)
      strcpy(s, d->elems[i].val);
  }
}

dict_t* dictadd(dict_t *d, char *k, char *v){
  if(dictlook(d, k) == NULL ){
    if(d->size < DICT_INITSIZE){
      strncpy(d->elems[d->size].key, k, DICTENT_KEYLENGTH);
      strncpy(d->elems[d->size].val, v, DICTENT_VALLENGTH);
      d->size++;
    }else{
      fputs("Le dictionnaire est plein.", stderr);
      }
  }else{
    fputs("Cette définition est déjà attribuée", stderr);
    }
  return d;
}

dict_t* dictup(dict_t *d, char *k, char *v){
  dictent_t *key = dictlook(d, k); 
  if(key != NULL){
    strncpy(key->val, v, DICTENT_VALLENGTH);
  }else{
    fputs("Cette définition n'a pas été utilisée veuillez utiliser dictadd", stderr);
  }
  return d;
}

dict_t* dictrm(dict_t *d, char *k){
  dictent_t *key = dictlook(d, k);
  if(key != NULL){
    int i=0;
    for(i; i<d->size-1; i++){
      d->elems[i] = d->elems[i+1];
    }
    d->size--;
  }else{
    fputs("Définition introuvable", stderr);
  }
  return *d;
}


int main(){
  dict_t d = dictcreate();
  dictent_t un = dictentcreate("un", "1");
  dict_t *dic = &d;
  dic = dictadd(dic, "un", "1");
  dic = dictadd(dic, "deux", "2");
  dic = dictadd(dic, "trois", "3");
  dic = dictadd(dic, "quatre", "4");
  dic = dictadd(dic, "cinq", "5");
  dictdump(dic);
  /*d = dictup(d, "deux", "de");
  dictdump(d);
  d = dictrm(d, "deux");
  dictdump(d);*/
  /*int n = sizeof(d);
  printf("\n %d \n", n);
  int m = sizeof(un);
  printf("\n %d \n", m);*/
}
