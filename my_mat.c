#include <stdio.h>
#include "my_mat.h"

int isPathExist(int graph[10][10],int i,int j);

void getMatrix(int mat[10][10]){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf(" %d\t", &mat[i][j]);
        }
    }
    printf("finished filling the matrix\n");
}
void isPath(int graph[10][10]){
    int i,j;
    printf("enter i and j to check if theres a path: ");
    scanf(" %d %d", &i,&j);
    int isPathE = isPathExist(graph,i,j); 
    if(isPathE == 1){
        printf("True\n");
    }
    else {
        printf("False\n");
    }
} 

int isPathExist(int graph[10][10],int i,int j){
    if (graph[i][j] != 0) {
        // There isn't a direct edge from i to j
            return 1;
    }

    if (i==j)
    {
       return 0;
    }
    // Check if there is an indirect path through other vertices
    for (int k = 0; k < 10; k++) {
        if(k != i && k != j){
            if (graph[i][k] != 0) {
                return isPathExist(graph, k, j);
            }
        }
    } 
    return 0;
}
void printShortestPath(int path[10][10]){
int i,j;
printf("enter i and j to check what is the shortest path: ");
scanf("%d %d", &i , &j);
    if(path[i][j]==0){
        printf("the shortest path is: -1");
    }
    else{
    printf("the shortest path is: %d\n", path[i][j]);
    }
}
void shortestPath(int graph[10][10]){
   int dist[10][10];

    // Initialize the solution matrix with the same values as the input graph
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            dist[i][j] = graph[i][j];
        }
    }
    // Main algorithm
    for (int k = 0; k < 10; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < 10; i++) {
            // Pick all vertices as destination for the above picked source
            for (int j = 0; j < 10; j++) {
                // If vertex k is on the shortest path from i to j,
                // then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printShortestPath(dist);
}
