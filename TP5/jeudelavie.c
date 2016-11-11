#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct univ{char **m; int size;};

struct univ *init_univ(int n){
  struct univ *u  = (struct univ *) malloc(sizeof(struct univ)); //on peut remplacer sizeof(struct univ) par sizeof(u)
  u->m = (char **) malloc(n * sizeof(char *));
  u->size = n;
  int i=0;
  for(i; i<n; i++){
    u->m[i] = (char *)malloc(n * sizeof(char));
  }
  int j;
  srand(time(NULL));
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      if((rand()%2) >= 0.5)
	u->m[i][j] = '1';
      else
	u->m[i][j] = '0';      
    }
  }
  return u;
}

void afficheUnivers(struct univ *u){
  int i;
  int j;
  for(i=0; i<u->size; i++){
    for(j=0; j<u->size; j++){
      printf("%c ", u->m[i][j]);
    }printf("%c", '\n');
  }
}

char left(struct univ *u, int i, int j){
  if(j != 0)
    return u->m[i][j-1];
  else
    return u->m[i][u->size-1];
}

char right(struct univ *u, int i, int j){
  if(j != u->size-1)
    return u->m[i][j+1];
  else
    return u->m[i][0];
}

char up(struct univ *u, int i, int j){
  if(i != 0)
    return u->m[i-1][j];
  else
    return u->m[u->size-1][j];
}

char down(struct univ *u, int i, int j){
  if(i != u->size-1)
    return u->m[i+1][j];
  else
    return u->m[0][j];
}

char up_left(struct univ *u, int i, int j){
  if(i != 0){
    if(j !=0)
      return u->m[i-1][j-1];
    else
      return u->m[i-1][u->size-1];
  }
  else{
    if(j != 0)
      return u->m[u->size-1][j-1];
    else
      return u->m[u->size-1][u->size-1];
  }
}

char up_right(struct univ *u, int i, int j){
  if(i != 0){
    if(j != u->size-1)
      return u->m[i-1][j+1];
    else
      return u->m[i-1][0];
  }
  else{
    if(j != u->size-1)
      return u->m[u->size-1][j+1];
    else
      return u->m[u->size-1][u->size-1];
  }
}

char down_left(struct univ *u, int i, int j){
  if(i != u->size-1){
    if(j != 0)
      return u->m[i+1][j-1];
    else
      return u->m[i+1][u->size-1];
  }
  else{
    if(j != 0)
      return u->m[0][j-1];
    else
      return u->m[0][u->size-1];
  }
}

char down_right(struct univ *u, int i, int j){
  if(i != u->size-1){
    if(j != u->size-1)
      return u->m[i+1][j+1];
    else
      return u->m[i+1][0];
  }
  else{
    if(j != u->size-1)
      return u->m[0][j+1];
    else
      return u->m[0][0];
  }
}

char meurt(struct univ *u, int i, int j){
  int c = 0;
  if(left(u, i, j) == '1')
    c++;
  if(right(u, i, j) == '1')
    c++;
  if(up(u, i, j) == '1')
    c++;
  if(down(u, i, j) == '1')
    c++;
  if(up_left(u, i, j) == '1')
    c++;
  if(up_right(u, i, j) == '1')
    c++;
  if(down_left(u, i, j) == '1')
    c++;
  if(down_right(u, i, j) == '1')
    c++;

  if(c > 1 && c < 4)
    return '1';
  else
    return '0';
}

char nait(struct univ *u, int i, int j){
  int c = 0;
  if(left(u, i, j) == '1')
    c++;
  if(right(u, i, j) == '1')
    c++;
  if(up(u, i, j) == '1')
    c++;
  if(down(u, i, j) == '1')
    c++;
  if(up_left(u, i, j) == '1')
    c++;
  if(up_right(u, i, j) == '1')
    c++;
  if(down_left(u, i, j) == '1')
    c++;
  if(down_right(u, i, j) == '1')
    c++;
  
  if(c == 3)
    return '1';
  else
    return '0';
}

void step(struct univ *u){
  struct univ *unext = init_univ(u->size);
  int i, j;
  for(i=0; i<u->size; i++){
    for(j=0; j<u->size; j++){
      if(u->m[i][j] == '1')
	unext->m[i][j] = meurt(u, i, j);
      else
	unext->m[i][j] = nait(u, i, j);
    }
  }
  afficheUnivers(unext);
  printf("%c", '\n');
  u->m = unext->m;
}

int main(){
  struct univ *u = init_univ(8);
  int i=0;
  for(i; i<5; i++){
    step(u);
    sleep(1);
  }
  return 0;
}
