#include <stdio.h>
#include <stdlib.h>

#define N 9
#define MAX 20

int adj[N + 1][N + 1] = {
    
    {0},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 0}, 
    {0, 1, 0, 1, 0, 1, 0, 0, 0, 0}, 
    {0, 0, 1, 0, 0, 0, 1, 0, 0, 0}, 
    {0, 1, 0, 0, 0, 1, 0, 1, 0, 0}, 
    {0, 0, 1, 0, 1, 0, 1, 0, 1, 0}, 
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 1}, 
    {0, 0, 0, 0, 1, 0, 0, 0, 1, 0}, 
    {0, 0, 0, 0, 0, 1, 0, 1, 0, 1}, 
    {0, 0, 0, 0, 0, 0, 1, 0, 1, 0}  
};

void BFS(int start) {
    int visited[N + 1] = {0};
    int queue[MAX], front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS order: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 1; i <= N; i++) {
            if (adj[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void DFS(int start) {
    int visited[N + 1] = {0};
    int stack[MAX], top = -1;

    stack[++top] = start;

    printf("DFS order: ");
    while (top >= 0) {
        int node = stack[top--];
        if (!visited[node]) {
            visited[node] = 1;
            printf("%d ", node);
            // push neighbors in decreasing order
            for (int i = N; i >= 1; i--) {
                if (adj[node][i] && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
    printf("\n");
}

int main() {
    BFS(1);
    DFS(1);
    return 0;
}
