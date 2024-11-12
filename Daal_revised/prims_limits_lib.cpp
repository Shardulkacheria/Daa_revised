#include <iostream>
#include <limits>
#define MAX 100
using namespace std;

void prim_algorithm(int cost[MAX][MAX], int n) {
    int T[MAX][2];  
    int selected_vertices[MAX] = {0};  
    int T_size = 0;  

    selected_vertices[0] = 1;  // Start from the first vertex

    while (T_size < n - 1) {
        int min_cost = numeric_limits<int>::max();
        int u = -1, v = -1;

        for (int i = 0; i < n; ++i) {
            if (selected_vertices[i]) {
                for (int j = 0; j < n; ++j) {
                    if (!selected_vertices[j] && cost[i][j] && cost[i][j] < min_cost) {
                        min_cost = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {  // Check if a valid edge was found
            T[T_size][0] = u;
            T[T_size][1] = v;
            ++T_size;
            selected_vertices[v] = 1;

            cout << "Edge " << u << " - " << v << "\tWeight: " << min_cost << endl;
        } else {
            break;
        }
    }

    if (T_size < n - 1) {
        cout << "No spanning tree exists." << endl;
    } else {
        // Output the Minimum Spanning Tree
        cout << "\nMinimum Spanning Tree:" << endl;
        for (int i = 0; i < T_size; ++i) {
            cout << T[i][0] << " - " << T[i][1] << endl;
        }
    }
}

int main() {
    int cost[MAX][MAX];
    int num_vertices;
    cout << "Enter the number of vertices: ";
    cin >> num_vertices;

    cout << "Enter the adjacency cost matrix:" << endl;
    for (int i = 0; i < num_vertices; ++i) {
        for (int j = 0; j < num_vertices; ++j) {
            cin >> cost[i][j];
        }
    }

    prim_algorithm(cost, num_vertices);

    return 0;
}

