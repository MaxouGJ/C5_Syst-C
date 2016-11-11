#include <stdio.h>
#include "strlib.h"

int main(int argc, char* argv[]) {
 int i = 1;
 int s = streq("-s", argv[1]);
 if (s == 0) {
     int s = streq("-s", argv[2]);
 }else{
     i = 2;
 }

 int n = streq("-n", argv[2]);
 if (n == 0) {
     int n = streq("-n", argv[1]);
 }else{
     i = 3;
 }
 for(i; i<argc; i++){
     printf("%s", argv[i]);
     if (s == 0) {
         printf(" ");
     }
 }
 if (n == 0) {
     printf("\n");
 }
}


