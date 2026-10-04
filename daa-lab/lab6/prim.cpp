#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void prims(int n, vector<vector<pair<int,int>>> &adj) {
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    pq.push({0, 0});
    int totalCost = 0;

    cout << "\nEdges in MST:\n";

    while(!pq.empty()) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(visited[u]) continue;

        visited[u] = true;
        totalCost += weight;

        if(parent[u] != -1)
            cout << parent[u] << " - " << u << " : " << weight << endl;

        for(auto it : adj[u]) {
            int v = it.first;
            int w = it.second;

            if(!visited[v]) {
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }

    cout << "Total Cost of MST: " << totalCost << endl;
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<pair<int,int>>> adj(n);

    cout << "Enter edges (u v weight):\n";
    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    prims(n, adj);

    return 0;
}
Enter number of vertices: 4
Enter number of edges: 5
Enter edges (u v weight):
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
