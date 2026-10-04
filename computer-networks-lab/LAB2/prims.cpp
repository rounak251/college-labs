#include <iostream>
#include <climits>
using namespace std;

#define V 9

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, idx;
    for (int i = 0; i < V; i++)
        if (!mstSet[i] && key[i] < min)
            min = key[i], idx = i;
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

    int parent[V], key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V - 1; i++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    cout << "Edges in MST:\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
}
