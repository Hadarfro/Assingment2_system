#include <stdio.h>
#include "my_mat.h"

int isPathExist(int graph[10][10],int i,int j,int check);

void getMatrix(int mat[10][10]){
    int num;
    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 10; j++) {
            printf("\nenter values for the matrix: ");
            mat[i][j] = scanf("%d", &num);
        }
    }
    printf("finished filling the matrix\n");
}
void isPath(int graph[10][10]){
    int i,j;
    printf("enter i and j to check if theres a path: ");
    scanf("%d %d", &i,&j);
    int isPathE = isPathExist(graph,i,j,0); 
    if(isPathE == 1){
        printf("true\n");
    }
    else if(isPathE == 0){
        printf("false\n");
    }
} 

int isPathExist(int graph[10][10],int i,int j,int check){
    if (graph[i][j] != 0) {
        // There isn't a direct edge from i to j
        if(check!=-1){
            return 1;
        }
        else{
            return 0;
        }
    }

    // Check if there is an indirect path through other vertices
    for (int k = 0; k < 10; k++) {
        if(k != i && k != j){
            if (graph[i][k] != 0) {
                return isPathExist(graph, k, j,check);
             }
             else{
                check = -1;
             }
        }
    }

    return 0; 
}
void printShortestPath(int path[10][10]){
int i,j;
scanf("%d %d", &i , &j);
    if(path[i][j]==0){
        printf("-1");
    }
    else{
    printf("the shortest path is: %d\n", path[i][j]);
    }
}
void shortestPath(int graph[10][10]){
   int dist[10][10];

    // Initialize the solution matrix with the same values as the input graph
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            dist[i][j] = graph[i][j];

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
