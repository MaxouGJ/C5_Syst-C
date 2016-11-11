#include <stdio.h>
#include <string.h>
#include "dict1.h"

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

void dictdump(dict_t d){
  int i=0;
  for(i; i<d.size; i++){
    fputs(d.elems[i].key, stderr);
    fputs(d.elems[i].val, stderr);
  }
}

int dictlook(dict_t d, char *k){
  int i=0;
  for(i; i<d.size; i++){
    if(strcmp(d.elems[i].key, k) == 0)
      return i;
  }
  return DICT_NOTFOUND;
}

void dictget(char *s, dict_t d, char *k){
  int i=1;
  for(i; i<d.size; i++){
    if(strcmp(d.elems[i].key, k) == 0)
      strcpy(s, d.elems[i].val);
  }
}

dict_t dictadd(dict_t d, char *k, char *v){
  if(dictlook(d, k) == -1){
    if(d.size < DICT_INITSIZE){
      strncpy(d.elems[d.size].key, k, DICTENT_KEYLENGTH);
      strncpy(d.elems[d.size].val, v, DICTENT_VALLENGTH);
      d.size++;
    }else{
      fputs("Le dictionnaire est plein.", stderr);
      }
  }else{
    fputs("Cette définition est déjà attribuée", stderr);
    }
  return d;
}

dict_t dictup(dict_t d, char *k, char *v){
  int key = dictlook(d, k); 
  if(key != -1){
    strncpy(d.elems[key].val, v, DICTENT_VALLENGTH);
  }else{
    fputs("Cette définition n'a pas été utilisée veuillez utiliser dictadd", stderr);
  }
  return d;
}

dict_t dictrm(dict_t d, char *k){
  int key = dictlook(d, k);
  if(key != -1){
    int i=key;
    for(i; i<d.size-1; i++){
      d.elems[i] = d.elems[i+1];
    }
    d.size--;
  }else{
    fputs("Définition introuvable", stderr);
  }
  return d;
}


int main(){
  dict_t d = dictcreate();
  dictent_t un = dictentcreate("un", "1");
  /* d = dictadd(d, "un", "1");
  d = dictadd(d, "deux", "2");
  d = dictadd(d, "trois", "3");
  d = dictadd(d, "quatre", "4");
  d = dictadd(d, "cinq", "5");
  dictdump(d);
  /*d = dictup(d, "deux", "de");
  dictdump(d);
  d = dictrm(d, "deux");
  dictdump(d);*/
  /*int n = sizeof(d);
  printf("\n %d \n", n);
  int m = sizeof(un);
  printf("\n %d \n", m);*/
}
