# Dijkstra Algorithm

## Description
Dijkstra's Algorithm is an algorithm used to solve the single source shortest path problem, which uses greedy algorithms to gradually expand the set of known shortest paths until reaching the target node.

![Image Title](123.png)

## Gold
Given a weighted directed graph and a source node to find the shortest path from the source node to all other nodes in the graph.

## Pseudocode

```
Dijkstra(Graph G, Node s)
    for each vertex v in V
        D[v] = G.weight(s, v) // ∞ for unreachable
    S = {s}
    while (V - S is not empty)
        u = Cheapest vertex reachable from V - S
        S.add(u)
        for each vertex v adjacent to u
            if (D[v] > D[u] + G.weight(u, v))
                D[v] = D[u] + G.weight(u,v)
```
### Algorithmic principle
The Dijkstra algorithm uses a greedy algorithm to gradually expand the set of known shortest paths until reaching the target node. Specifically, the algorithm maintains a distance array that records the shortest distance from the starting node to each node, as well as a set that records the nodes that have determined the shortest path. At each step, the algorithm selects the node with the smallest distance in the distance array that is not in the set, adds it to the set, and updates the distance array to reflect the shortest path from the starting node to that node.
>


## Algorithm implement
The Implementation of Algorithms in C++
```
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

```

## Time complexity
For a graph with V vertices and E edges, the time complexity of the Dijkstra algorithm is:
- Implement using adjacency matrix: O(V<sup>2</sup>).
- Implement priority queue using binary heap: O((V+E)logV) .
### Worse case
The worst-case time complexity is O((V<sup>2</sup> + E) log V). This is because even with heap optimization, each vertex may be inserted, deleted, and updated, with each of these operations having a time complexity of log V. If E approaches V<sup>2</sup>, then the overall complexity of heap operations may approach O(V<sup>2</sup> log V).

## Algorithm application
Dijkstra Algorithm is commonly used in search engines. Many websites use this algorithm to generate product links or push videos that users may be interested in. 
>
Another application of Dijkstra in daily life is reflected in logistics and transportation. Logistics companies typically use this algorithm to optimize routes, allocate goods, manage traffic flow, and other areas to improve efficiency and reduce costs.


## Output

### Graph Information:

![Image Title](3.png)
