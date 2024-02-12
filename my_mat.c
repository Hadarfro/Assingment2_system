#include <stdio.h>
#include "my_mat.h"
#define V 10

int graph[V][V];
int dist[V][V];
void getMatrix(){
    int num;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &num);
            graph[i][j] = num;
            dist[i][j] = num;
        }
    }
}
void printIsPath(){            
    int i,j;
    scanf("%d %d", &i,&j);
    shortestPath(); 
    if(i==j){
        printf("False\n");
        return;
    }
    if(dist[i][j] > 0){
        printf("True\n");
        return;
    }
    else {
        printf("False\n");
        return;
    }
} 

void printShortestPath(){
int i,j;
scanf("%d %d", &i , &j);
shortestPath();
if(i==j){
   printf("-1\n");
   return; 
}
    if(dist[i][j]==0){
        printf("-1\n");
        return;
    }
    else{
    printf("%d\n", dist[i][j]);
    return;
    }
}

void shortestPath(){

    // Main algorithm
    for (int k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < V; i++) {
            // Pick all vertices as destination for the above picked source
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j,
                // then update the value of dist[i][j]
                if(dist[i][k] != 0 && dist[k][j] != 0 && (dist[i][k] + dist[k][j] < dist[i][j] || dist[i][j] == 0)){
                    if (i!=j){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}

