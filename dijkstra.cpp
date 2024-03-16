#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <stack>

using namespace std;

const int INF = numeric_limits<int>::max(); // Infinity

// Structure for representing edges
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

// Structure for representing graphs
struct Graph {
    vector<vector<Edge>> adj;
    Graph(int n) : adj(n) {}
};

// Dijkstra's algorithm
void dijkstra(Graph& G, int s, vector<int>& D, vector<int>& prev) {
    int n = G.adj.size();
    vector<bool> visited(n, false);

    // Initialize distance array
    D.assign(n, INF);
    prev.assign(n, -1);
    D[s] = 0;

    // Priority queue for sorting by distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        // Update distances to adjacent vertices of u
        for (const Edge& e : G.adj[u]) {
            int v = e.to;
            int w = e.weight;
            if (D[v] > D[u] + w) {
                D[v] = D[u] + w;
                prev[v] = u;
                pq.push({D[v], v});
            }
        }
    }
}

// Get path from source to target vertex
stack<int> getPath(vector<int>& prev, int s, int t) {
    stack<int> path;
    for (int v = t; v != s; v = prev[v]) {
        path.push(v);
    }
    path.push(s);
    return path;
}

int main() {
    int n = 9; // Number of vertices in the graph
    Graph G(n);

    // Add edges
    G.adj[0].push_back(Edge(1, 4));
    G.adj[0].push_back(Edge(7, 8));
    G.adj[1].push_back(Edge(7, 11));
    G.adj[1].push_back(Edge(2, 8));
    G.adj[7].push_back(Edge(8, 7));
    G.adj[7].push_back(Edge(6, 1));
    G.adj[8].push_back(Edge(2, 2));
    G.adj[8].push_back(Edge(6, 6));
    G.adj[2].push_back(Edge(3, 7));
    G.adj[2].push_back(Edge(5, 4));
    G.adj[6].push_back(Edge(5, 2));
    G.adj[5].push_back(Edge(4, 10));
    G.adj[5].push_back(Edge(3, 14));
    G.adj[3].push_back(Edge(4, 9));

    vector<int> D, prev;
    dijkstra(G, 0, D, prev);

    cout << "Graph Information:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << " has edges to: ";
        if (!G.adj[i].empty()) {
            for (const Edge& e : G.adj[i]) {
                cout << "(" << e.to << ", " << e.weight << ") ";
            }
        }
        cout << endl;
    }
    cout << endl;

    // Output results
    for (int i = 1; i < n; ++i) {
        if (D[i] != INF) {
            cout << "Shortest distance from node 0 to " << i << " is " << D[i] << ", the path is 0";
            stack<int> path = getPath(prev, 0, i);
            path.pop(); // Pop the source vertex
            while (!path.empty()) {
                cout << " " << path.top();
                path.pop();
            }
            cout << endl;
        } else {
            cout << "No path from node 0 to " << i << endl;
        }
    }

    return 0;
}
