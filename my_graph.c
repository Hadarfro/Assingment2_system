#include <stdio.h>
#include "my_mat.h"
#include "my_mat.c"


int main() {
char letter;
int mat[10][10];
    printf("enter a letter:");
    letter = scanf("%c", &letter);
    while (letter!='D'||letter!= EOF) {
      if(letter == 'A'){
         getMatrix(mat);
         }
      if(letter == 'B'){
             isPath(mat);
        }
      if (letter == 'c') {
            shortestPath(mat);
         } 
      letter = scanf("%c", &letter);
     }
return 0;
}
    