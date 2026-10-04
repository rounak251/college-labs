#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int find(int parent[], int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent, parent[x]);
}

void unite(int parent[], int x, int y) {
    parent[find(parent, x)] = find(parent, y);
}

int main() {
    vector<Edge> edges = {
        {0,1,4},{0,7,8},{1,7,11},{1,2,8},
        {2,3,7},{3,4,9},{4,5,10},{3,5,14},
        {2,8,2},{8,6,6},{6,5,2},{7,6,1},{2,6,7}
    };

    sort(edges.begin(), edges.end(), cmp);

    int parent[9];
    for (int i = 0; i < 9; i++) parent[i] = i;

    int cost = 0;
    cout << "Edges in MST:\n";
    for (auto e : edges) {
        if (find(parent, e.u) != find(parent, e.v)) {
            unite(parent, e.u, e.v);
            cost += e.w;
            cout << e.u << " - " << e.v << " : " << e.w << endl;
        }
    }

    cout << "Total Cost = " << cost << endl;
}
