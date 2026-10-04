#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void dijkstra(int V, vector<vector<pair<int,int>>> &adj, int source) {
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    pq.push({0, source});

    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto &it : adj[node]) {
            int adjNode = it.first;
            int wt = it.second;

            if(d + wt < dist[adjNode]) {
                dist[adjNode] = d + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    cout << "\nShortest distances from source node " << source << ":\n";
    for(int i = 0; i < V; i++) {
        cout << "To vertex " << i << " = " << dist[i] << endl;
    }
}

int main() {

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<pair<int,int>>> adj(V);

    cout << "Enter edges (u v weight):\n";

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    dijkstra(V, adj, source);

    return 0;
}