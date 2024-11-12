#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;

struct Edge {
    int src, dest, weight;  // source vertex, destination vertex, weight of edge
};

// Comparator function to sort edges by weight
bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

class Graph {
    int V;  // Number of vertices
    vector<Edge> edges;  // Vector of all edges

public:
    Graph(int V) : V(V) {}

    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    int findParent(vector<int> &parent, int i) {
        if (parent[i] != i)
            parent[i] = findParent(parent, parent[i]);
        return parent[i];
    }

    void unionSets(vector<int> &parent, vector<int> &rank, int x, int y) {
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

    void kruskalMST() {
        vector<Edge> result;
        vector<int> parent(V), rank(V, 0);
        int totalWeight = 0; // To accumulate the total weight of the MST

        for (int i = 0; i < V; i++) parent[i] = i;

        sort(edges.begin(), edges.end(), compareEdges);

        for (const Edge &edge : edges) {
            int x = findParent(parent, edge.src);
            int y = findParent(parent, edge.dest);

            if (x != y) {
                result.push_back(edge);
                unionSets(parent, rank, x, y);
                totalWeight += edge.weight; // Add the weight of the edge to the total weight
            }
        }

        cout << "Edges in the MST:\n";
        for (const Edge &e : result) {
            cout << e.src << " - " << e.dest << " : " << e.weight << endl;
        }
        cout << "Total weight of MST: " << totalWeight << endl;
    }
};

int main() {
    int V, E;  // Number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph graph(V);

    cout << "Enter the edges (source, destination, weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    graph.kruskalMST();

    return 0;
}

