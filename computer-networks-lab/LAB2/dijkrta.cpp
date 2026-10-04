#include <iostream>
#include <climits>
using namespace std;

#define V 9

int minDist(int dist[], bool visited[]) {
    int min = INT_MAX, idx;
    for (int i = 0; i < V; i++)
        if (!visited[i] && dist[i] < min)
            min = dist[i], idx = i;
    return idx;
}

int main() {
    int graph[V][V] = {
        {0,4,0,0,0,0,0,8,0},
        {4,0,8,0,0,0,0,11,0},
        {0,8,0,7,0,4,0,0,2},
        {0,0,7,0,9,14,0,0,0},
        {0,0,0,9,0,10,0,0,0},
        {0,0,4,14,10,0,2,0,0},
        {0,0,0,0,0,2,0,1,6},
        {8,11,0,0,0,0,1,0,7},
        {0,0,2,0,0,0,6,7,0}
    };

    int dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, visited[i] = false;

    dist[0] = 0; // source = 'a'

    for (int i = 0; i < V - 1; i++) {
        int u = minDist(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    cout << "Shortest distances from source a:\n";
    for (int i = 0; i < V; i++)
        cout << "a -> " << i << " = " << dist[i] << endl;
}
