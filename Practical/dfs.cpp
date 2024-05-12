#include <iostream>
#include <vector>

using namespace std;

// Utility function for DFS traversal
void DFSUtil(vector<vector<int>>& graph, int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DFSUtil(graph, neighbor, visited);
        }
    }
}

// Function to perform DFS traversal on a graph
void DFS(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);

    cout << "DFS Traversal: ";
    DFSUtil(graph, start, visited);
    cout << endl;
}

int main() {
    // Test case
    vector<vector<int>> graph = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    int start = 0;

    DFS(graph, start);

    return 0;
}
