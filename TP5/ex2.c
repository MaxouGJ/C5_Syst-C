#include <stdio.h>

struct st3 { int a; int b; int c; };

int main(){
  int t[30];
  int *p = t;
  char *s = (char *) t;
  struct st3 *pst3 = (struct st3 * ) t;

  int i;
  for(i=0; i<30; i++)
    t[i] = 10 * i;

  printf("%d ", *p + 2);
  printf("\n");
  
  printf("%d ", *(p + 2));
  printf("\n");
  
  printf("%p ", &p + 1);
  printf("\n");
  
  printf("%p ", &t[4] - 3);
  printf("\n");

  printf("%p ", t + 3);
  printf("\n");

  printf("%d ", &t[7] - p);
  printf("\n");

  printf("%p ",  p + (*p - 10));
  printf("\n");

  printf("%d ", *(p + *(p + 8) - t[7]));
  printf("\n");

  printf("%d ", s[4]);
  printf("\n");

  printf("%d ", &(s[4]) - &(s[2]));
  printf("\n");

  printf("%d ", pst3[3].b);
  printf("\n");

  printf("%d ", ((struct st3 *)&t[6]) -pst3);
  printf("\n");

}
