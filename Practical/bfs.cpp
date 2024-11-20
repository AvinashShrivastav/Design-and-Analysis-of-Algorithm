#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS traversal on a graph
// Function to perform Breadth-First Search (BFS) on a graph
void BFS(vector<vector<int>>& graph, int start) {
    // Get the number of nodes in the graph
    int n = graph.size();

    // Create a vector to keep track of visited nodes. Initialize all nodes as not visited
    vector<bool> visited(n, false);

    // Create a queue to hold nodes for BFS
    queue<int> q;

    // Add the start node to the queue and mark it as visited
    q.push(start);
    visited[start] = true;

    // Continue until all nodes have been visited
    while (!q.empty()) {
        // Get the next node from the front of the queue
        int node = q.front();
        q.pop();

        // Print the node
        cout << node << " ";

        // Visit all the neighbors of the current node
        for (int neighbor : graph[node]) {
            // If the neighbor has not been visited yet, add it to the queue and mark it as visited
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
