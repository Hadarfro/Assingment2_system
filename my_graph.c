#include <stdio.h>
#include "my_mat.c"
#include "my_mat.h"


int my_graph() {
char letter;
int mat[10][10];
    printf("enter a letter:");
    while (scanf("%c", &letter)!='D') {
     if(letter == 'A'){
         getMatrix(mat);
         }
      if(letter == 'B'){
             isPath(mat);
        }
        if (letter == 'c') {
            shortestPath(mat);
         } 
     }
return 0;
}
    