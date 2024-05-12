#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to find minimum spanning tree using Prim's algorithm
void primMST(vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    int totalWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        totalWeight += w;
        cout << "Edge: " << u << " - " << w << endl;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!visited[v]) {
                pq.push({weight, v});
            }
        }
    }

    cout << "Total weight of MST: " << totalWeight << endl;
}

int main() {
    // Test case
    vector<vector<pair<int, int>>> graph = {{{1, 5}, {2, 1}},
                                             {{0, 5}, {2, 3}, {3, 6}},
                                             {{0, 1}, {1, 3}, {3, 7}},
                                             {{1, 6}, {2, 7}}};
    int start = 0;

    cout << "Minimum Spanning Tree using Prim's algorithm:\n";
    primMST(graph, start);

    return 0;
}
