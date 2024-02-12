#include <stdio.h>
#include "my_mat.h"
#define whight_bag 20
#define size 5

int weights[size];
int values[size];
int selected_bool[size];
char items[size];


void  insertToList(){
    for (int i = 0; i < size; i++) {
            scanf(" %c", &items[i]);
            scanf(" %d", &values[i]);
            scanf(" %d", &weights[i]);
            selected_bool[i] = 0;
        }
}

int knapSack (int weights[], int values[] , int selected_bool[]){
  int table[size+1][whight_bag+1];
  int w = whight_bag;
  int sumValue = 0;
  for (int i = 0; i <= size; i++) {
    for (int j = 0; j <= whight_bag; j++){
        if(i==0||j==0){
            table[i][j] = 0;
        }
        else if(weights[i-1]>j){
            table[i][j] = table[i-1][j];
        }
        else{
            table[i][j] = (table[i-1][j] > (table[i-1][j-weights[i-1]] + values[i-1])) ? table[i-1][j] : (table[i-1][j-weights[i-1]] + values[i-1]);
        }
      }
  }
    for (int j = size; j > 0; j--){
        if(table[j][w]!=table[j-1][w]){
            sumValue += values[j-1];
            w -= weights[j-1];
            selected_bool[j-1] = 1;
        }
    }   
  
  return sumValue;
}

//*********************start main******************************
int main(){
    int maxProfit = 0;
    insertToList();
     maxProfit = knapSack (weights, values, selected_bool);
    printf("Maximum profit : %d \n", maxProfit);
    printf("Selected items: ");
    for (int i = 0; i < size; i++)
    {
        if (selected_bool[i] == 1){
            printf(" %c", items[i]);
        }
       
    }
    printf("\n");
    return 0;
}