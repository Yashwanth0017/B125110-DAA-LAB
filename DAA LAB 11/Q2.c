/*2. [Multi-Source BFS for Radius-Constrained Voronoi Cell Partitioning] 
You are given: ◦ An unweighted, undirected graph G = (V,E). 
◦ Aset of K designated hub vertices H = {h1,h2,...,hK} ⊆ V, indexed from 1 to K. 
◦ An integer radius threshold R ≥ 0. Let dist(u,v) denote the shortest path distance (minimum number of edges) between vertices u and v in G.
 For every vertex v ∈ V, assign an ownership label owner[v] ∈ {1,2,...,K}∪{−1} according to the following rules: 
 1. Distance Metric: Find the distance from v to each service hub: di = dist(v,hi) for all i ∈ {1,...,K}. Let dmin(v) = min1≤i≤K di. 
 2. Reachability Threshold (R): If dmin(v) > R, vertex v lies outside the service coverage area. Set owner[v] = −1. 
 3. Closest Hub Assignment: If dmin(v) ≤ R, assign v to the hub hi that minimizes di
 .4. Deterministic Tie-Breaking: If multiple hubs achieve the exact same minimum distance dmin(v), choose the hub with the smallest numerical index i. 
 Objective: Output the array owner[︁1...|V |]︁ containing the assigned hub index (or −1 if unassigned) and the corresponding shortest distance to that hub for every vertex. 
 By choosing the proper input representation, write a program in C to validate your algorithm and derive the complexity analysis of your algorithm.*/
#include <stdio.h>
#define MAXV 1000
#define MAXE 10000

int head[MAXV], to[2 * MAXE], next[2 * MAXE];
int edgeCount = 0;

void addEdge(int u, int v) {
    to[edgeCount] = v;
    next[edgeCount] = head[u];
    head[u] = edgeCount++;
}

int main() {
    int n, m, k, R;

    // Initialize adjacency list
    for(int i = 0; i < MAXV; i++)
        head[i] = -1;

    printf("Enter number of vertices and edges: ");
    scanf("%d%d", &n, &m);

    printf("Enter undirected edges (u v):\n");

    for(int i = 0; i < m; i++) {
        int u, v;

        printf("Edge %d: ", i + 1);
        scanf("%d%d", &u, &v);

        addEdge(u, v);
        addEdge(v, u);
    }

    printf("Enter number of hubs and radius R: ");
    scanf("%d%d", &k, &R);

    int dist[MAXV], owner[MAXV];
    int q[MAXV];

    for(int i = 0; i < n; i++) {
        dist[i] = -1;
        owner[i] = -1;
    }

    int front = 0, rear = 0;

    // Insert hubs in increasing index order
    printf("Enter hub vertices in index order:\n");

    for(int i = 1; i <= k; i++) {
        int h;

        printf("Hub %d: ", i);
        scanf("%d", &h);

        dist[h] = 0;
        owner[h] = i;

        q[rear++] = h;
    }

    // Multi-source BFS
    while(front < rear) {

        int u = q[front++];

        for(int e = head[u]; e != -1; e = next[e]) {

            int v = to[e];

            if(dist[v] == -1) {

                dist[v] = dist[u] + 1;
                owner[v] = owner[u];

                q[rear++] = v;
            }
        }
    }

    printf("\nVertex\tOwner\tDistance\n");

    for(int i = 0; i < n; i++) {

        if(dist[i] == -1 || dist[i] > R)
            owner[i] = -1;

        printf("%d\t%d\t%d\n",
               i, owner[i], dist[i]);
    }

    return 0;
}
