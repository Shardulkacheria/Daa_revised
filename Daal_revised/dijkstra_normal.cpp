#include <iostream>
#define MAX 100
#define INF 999999 // Define a large value to represent infinity
using namespace std;

// Function to print the path from the source to the destination
void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        return;
    }
    printPath(parent, parent[j]);
    cout << parent[j] << " - " << j << endl;
}

// Dijkstra's algorithm to find the shortest path
void dijkstra(int graph[MAX][MAX], int V, int src, int dest) {
    int dist[MAX];    // Array to hold the shortest distance from src to i
    bool visited[MAX]; // Array to mark visited vertices
    int parent[MAX];  // Array to hold the parent of each vertex

    // Initialize distance, visited, and parent arrays
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1; // Initialize parent array
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int min = INF, min_index;
        // Find the vertex with the minimum distance from the set of unvisited vertices
        for (int v = 0; v < V; v++)
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        int u = min_index;
        visited[u] = true;

        if (u == dest) break; // If we reached the destination, no need to continue

        // Update the distance of adjacent vertices of the selected vertex
        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u; // Set the parent of v to u
            }
    }

    // Check if a path exists between the source and destination
    if (dist[dest] == INF) {
        cout << "There is no path between vertex " << src << " and vertex " << dest << "." << endl;
    } else {
        cout << "Shortest distance from vertex " << src << " to vertex " << dest << " is: " << dist[dest] << endl;
        cout << "Edges in the shortest path:" << endl;
        printPath(parent, dest);
    }
}

int main() {
    int V, E;
    int graph[MAX][MAX] = {0};
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // Remove this line if the graph is directed
    }
    int src, dest;
    cout << "Enter the source vertex: ";
    cin >> src;
    cout << "Enter the destination vertex: ";
    cin >> dest;
    
    dijkstra(graph, V, src, dest);
    
    return 0;
}

