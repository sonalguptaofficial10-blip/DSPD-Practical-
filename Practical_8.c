#include <stdio.h>
#include <stdlib.h>

#define MAX 30


struct Edge {
    int src, dest, weight;
};


struct Subset {
    int parent;
    int rank;
};


int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}


void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function for qsort (sort by weight)
int compareEdges(const void* a, const void* b) {
    struct Edge* e1 = (struct Edge*)a;
    struct Edge* e2 = (struct Edge*)b;
    return e1->weight - e2->weight;
}

// Kruskal’s algorithm
void KruskalMST(struct Edge edges[], int V, int E) {
    struct Edge result[MAX]; // Store MST edges
    int e = 0; // Index for result[]
    int i = 0; // Index for sorted edges

    // Step 1: Sort edges in increasing order by weight
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    // Step 2: Create V subsets with single elements
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Step 3: Pick the smallest edge and add to result if no cycle
    while (e < V - 1 && i < E) {
        struct Edge next = edges[i++];

        int x = find(subsets, next.src);
        int y = find(subsets, next.dest);

    
        if (x != y) {
            result[e++] = next;
            Union(subsets, x, y);
        }
    }

    // 
    printf("\nEdges in the Minimum Spanning Tree:\n");
    int totalWeight = 0;
    for (i = 0; i < e; ++i) {
        printf("%d -- %d  == %d\n", result[i].src + 1, result[i].dest + 1, result[i].weight);
        totalWeight += result[i].weight;
    }
    printf("Minimum Cost of Spanning Tree = %d\n", totalWeight);

    free(subsets);
}

int main() {
    int V, E;
    struct Edge edges[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter each edge (source destination weight):\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
        edges[i].src--;   
        edges[i].dest--;
    }

    KruskalMST(edges, V, E);
    return 0;
}
