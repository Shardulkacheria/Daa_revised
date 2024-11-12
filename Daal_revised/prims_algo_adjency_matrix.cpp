#include <iostream>
#define MAX 100
#define INF 99999  // A large value to represent infinity
using namespace std;

// Function to implement Prim's algorithm
void prim_algorithm(int cost[MAX][MAX], int n) {
    int T[MAX][2];  // Array to store the edges of the MST
    int selected_vertices[MAX] = {0};  // Array to keep track of selected vertices
    int T_size = 0;  // Counter for the number of edges in MST

    selected_vertices[0] = 1;  // Start from the first vertex

    // Loop until we have n-1 edges in the MST
    while (T_size < n - 1) {
        int min_cost = INF;  // Set the initial minimum cost to infinity
        int u = -1, v = -1;  // Variables to store the vertices of the selected edge

        // Find the edge with the smallest weight
        for (int i = 0; i < n; ++i) {
            if (selected_vertices[i]) {  // Check if the vertex is already included in MST
                for (int j = 0; j < n; ++j) {
                    // Check for the smallest edge connecting the selected vertex to an unselected vertex
                    if (!selected_vertices[j] && cost[i][j] && cost[i][j] < min_cost) {
                        min_cost = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        // If a valid edge is found, add it to the MST
        if (u != -1 && v != -1) {
            T[T_size][0] = u;
            T[T_size][1] = v;
            ++T_size;
            selected_vertices[v] = 1;  // Mark the vertex as selected
            cout << "Edge " << u << " - " << v << "\tWeight: " << min_cost << endl;
        } else {
            break;  // If no valid edge is found, exit the loop
        }
    }

    if (T_size < n - 1) {        // If we have less than n-1 edges, no MST exists
        cout << "No spanning tree exists." << endl;
    } else {    // Display the edges of the Minimum Spanning Tree
        cout << "\nMinimum Spanning Tree:" << endl;
        for (int i = 0; i < T_size; ++i) {
            cout << T[i][0] << " - " << T[i][1] << endl;
        }
    }
}

int main() {
    int cost[MAX][MAX];  // Adjacency matrix to store the graph
    int num_vertices;

    cout << "Enter the number of vertices: ";        // Input number of vertices
    cin >> num_vertices;

    cout << "Enter the adjacency cost matrix:" << endl;    // Input the adjacency cost matrix
    for (int i = 0; i < num_vertices; ++i) {
        for (int j = 0; j < num_vertices; ++j) {
            cin >> cost[i][j];
        }
    }

    prim_algorithm(cost, num_vertices);

    return 0;
}

