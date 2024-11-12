#include <iostream>
using namespace std;
#define MAX 100 

struct Edge {
    int src, dest, weight;
};

void swapEdges(Edge &a, Edge &b) {  // Swap edges to rearrange them in ascending order
    Edge temp = a;
    a = b;
    b = temp;
}

// A simple function to sort edges based on their weight
void sortEdges(Edge edges[], int E) {   // Bubble sort
    for (int i = 0; i < E-1; i++) {
        for (int j = 0; j < E-i-1; j++) {
            if (edges[j].weight > edges[j+1].weight) {
                swapEdges(edges[j], edges[j+1]);
            }
        }
    }
}

// Find the root of a subset with path compression
int findParent(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = findParent(parent, parent[i]);
    return parent[i];
}

// Union by rank to combine two subsets
void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = findParent(parent, x);
    int rootY = findParent(parent, y);

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

void kruskalMST(int V, int E, Edge edges[]) {
    Edge result[MAX]; // To store the resulting MST
    int parent[MAX], rank[MAX] = {0};
    int totalWeight = 0;
    int resultSize = 0;

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    sortEdges(edges, E);

    for (int i = 0; i < E; i++) {
        int x = findParent(parent, edges[i].src);
        int y = findParent(parent, edges[i].dest);

        if (x != y) {
            result[resultSize++] = edges[i];
            unionSets(parent, rank, x, y);
            totalWeight += edges[i].weight;
        }
    }

    cout << "Edges in the MST:\n";
    for (int i = 0; i < resultSize; i++) {
        cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << endl;
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Edge edges[MAX];

    cout << "Enter the edges (source, destination, weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    kruskalMST(V, E, edges);

    return 0;
}

