#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

// ---------- Prim's Algorithm ----------
void prims(int n, vector<vector<pair<int,int>>> &adj) {
    vector<bool> visited(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,0});
    int totalCost = 0;

    cout << "\nPrim's MST Edges:\n";

    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int weight = it.first;
        int u = it.second;

        if(visited[u]) continue;

        visited[u] = true;
        totalCost += weight;

        for(auto x : adj[u]) {
            int v = x.first;
            int w = x.second;

            if(!visited[v]) {
                pq.push({w,v});
                cout << u << " - " << v << " : " << w << endl;
            }
        }
    }

    cout << "Total Cost (Prim): " << totalCost << endl;
}

// ---------- Kruskal's Algorithm ----------

int findParent(int v, vector<int> &parent) {
    if(parent[v] == v)
        return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSet(int a, int b, vector<int> &parent) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    parent[a] = b;
}

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

void kruskal(int n, vector<Edge> edges) {
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n);
    for(int i=0;i<n;i++)
        parent[i] = i;

    int totalCost = 0;

    cout << "\nKruskal's MST Edges:\n";

    for(auto e : edges) {
        if(findParent(e.u, parent) != findParent(e.v, parent)) {
            cout << e.u << " - " << e.v << " : " << e.w << endl;
            totalCost += e.w;
            unionSet(e.u, e.v, parent);
        }
    }

    cout << "Total Cost (Kruskal): " << totalCost << endl;
}

// ---------- Main ----------
int main() {
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<pair<int,int>>> adj(n);
    vector<Edge> edges;

    cout << "Enter edges (u v weight):\n";

    for(int i=0;i<e;i++) {
        int u,v,w;
        cin >> u >> v >> w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

        edges.push_back({u,v,w});
    }

    prims(n, adj);
    kruskal(n, edges);

    return 0;
}