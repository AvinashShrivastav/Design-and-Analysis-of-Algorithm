#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS traversal on a graph
void BFS(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    // Test case
    vector<vector<int>> graph = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    int start = 0;

    cout << "BFS Traversal: ";
    BFS(graph, start);
    cout << endl;

    return 0;
}
