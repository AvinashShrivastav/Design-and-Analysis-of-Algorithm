#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find minimum spanning tree using Prim's algorithm
void primMST(vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size(); // Number of vertices in the graph
    vector<bool> visited(n, false); // Mark all vertices as not visited
    vector<int> minWeight(n, INT_MAX); // Initialize minimum weight of edges to all vertices as infinity
    vector<int> parent(n, -1); // Initialize parent array to track MST edges

    minWeight[start] = 0; // Set weight of start vertex as 0

    // Loop through all vertices
    for (int i = 0; i < n - 1; ++i) {
        int u = -1;
        // Find the vertex with minimum weight edge from the set of unvisited vertices
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && (u == -1 || minWeight[j] < minWeight[u])) {
                u = j;
            }
        }

        visited[u] = true; // Mark the selected vertex as visited

        // Update the minimum weight and parent for adjacent vertices of the selected vertex
        for (auto& edge : graph[u]) {
            int v = edge.first; // Adjacent vertex
            int weight = edge.second; // Weight of edge
            if (!visited[v] && weight < minWeight[v]) {
                parent[v] = u; // Update parent
                minWeight[v] = weight; // Update minimum weight
            }
        }
    }

    // Output the minimum spanning tree edges
    int totalWeight = 0;
    cout << "Minimum Spanning Tree Edges:\n";
    for (int i = 0; i < n; ++i) {
        if (parent[i] != -1) {
            cout << "Edge: " << parent[i] << " - " << i << " Weight: " << minWeight[i] << endl;
            totalWeight += minWeight[i];
        }
    }

    // Output the total weight of MST
    cout << "Total weight of MST: " << totalWeight << endl;
}

int main() {
    // Test case
    vector<vector<pair<int, int>>> graph = {{{1, 5}, {2, 1}},
                                             {{0, 5}, {2, 3}, {3, 6}},
                                             {{0, 1}, {1, 3}, {3, 7}},
                                             {{1, 6}, {2, 7}}};
    int start = 0; // Starting vertex for Prim's algorithm

    // Output the minimum spanning tree using Prim's algorithm
    cout << "Minimum Spanning Tree using Prim's algorithm:\n";
    primMST(graph, start);

    return 0; 
}
