#include <stdio.h>
#include "my_mat.h"
#define whight_bag 20
#define size 5

int weights[size];
int values[size];
int selected_bool[size];
int result[size];
char items[size];


void  insertToList(){
    int value,whight;
    char item;
    for (size_t i = 0; i < 5; i++) {
            printf("enter item:");
            scanf("%c", (items[i]));
            printf("enter value:");
            scanf("%d", &(values[i]));
            printf("enter whight:");
             scanf("%d", &(weights[i]));
            selected_bool[i] = 0;
        }
}

int knapSack (int weights[], int values[] , int selected_bool[]){
  int table[size+1][size+1];
  int w = whight_bag;
  int wItem , vItem ;
  int sumValue = 0;
  for (size_t i = 1; i < size+1; i++) {
    wItem = weights[i-1];
    vItem = values[i-1];
    for (size_t j = 1; j < whight_bag+1; j++){
        if(wItem>j){
            table[i][j] = table[i-1][j];
        }
        else{
            table[i][j] = (table[i-1][j] > (table[i-1][j-wItem] + vItem)) ? table[i-1][j] : (table[i-1][j-wItem] + vItem);
        }
      }
    for (int j = size - 1; j >= 0; j--){
        if(table[j][w]!=table[j-1][w]){
            wItem = weights[j-1];
            vItem = values[j-1];
            sumValue += values[j-1];
            w -= wItem;
            selected_bool[j] = 1;
        }
    }
    return sumValue;  
  }
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