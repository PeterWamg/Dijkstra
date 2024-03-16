# Dijkstra Algorithm

The Dijkstra algorithm is a classic algorithm used to find the shortest path from a single source node to all other nodes in a weighted graph.

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
