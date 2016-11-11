#include <stdio.h>

void affichage(int a, int b, int c, int *p1, int *p2){

  printf("%d ", a);
  printf("%d ", b);
  printf("%d ", c);
  printf("\t");
  printf("%d ", *p1);
  printf("%p ", p1);
  printf("%d ", *p2);
  printf("%p ", p2);
  printf("\n");
  
}

int main(){

  int a, b, c, *p1, *p2;

  a = 1, b = 2, c = 3;
  affichage(a, b, c, p1, p2);
  
  p1 = &a, p2 = &c;
  affichage(a, b, c, p1, p2);

  *p1 = (*p2)++;
  affichage(a, b, c, p1, p2);
  
  p1 = p2;
  affichage(a, b, c, p1, p2);
  
  p2 = &b;
  affichage(a, b, c, p1, p2);

  *p1 -= *p2;
  affichage(a, b, c, p1, p2);

  ++*p2;
  affichage(a, b, c, p1, p2);

  *p1 *= *p2;
  affichage(a, b, c, p1, p2);

  a = ++*p2 * *p1;
  affichage(a, b, c, p1, p2);

  p1 = &a;
  affichage(a, b, c, p1, p2);

  *p2 = *p1 /= *p2;
  affichage(a, b, c, p1, p2);
  
}
