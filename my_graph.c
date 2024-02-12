#include <stdio.h>
#include "my_mat.h"
#include "my_mat.c"


int main() {
char letter;
    
     do {
        letter = getchar();
        switch (letter) {
            case 'A':
                getMatrix();
                break;
            case 'B':
                printIsPath();
                break;
            case 'C':
                printShortestPath();
                break;
            case 'D':
                // Optional: Add code for 'D' case if needed
                break;
            case EOF:
                // Optional: Add code for EOF case if needed
                break;
            default:
                printf("Invalid letter. Please enter A, B, C, or D.\n");
                break;
        }
        // Consume any remaining characters in the input buffer
        while (getchar() != '\n');

    } while (letter != 'D' && letter != EOF);

    return 0;
}
    