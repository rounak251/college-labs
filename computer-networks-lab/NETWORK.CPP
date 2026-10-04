#include <iostream>
using namespace std;

int main() {
    int n = 8;   // number of nodes
    int adj[9][9] = {0};

    // Given edges (u, v, weight)
    adj[1][3] = 5;
    adj[1][2] = 9;
    adj[2][1] = 3;
    adj[2][4] = 18;
    adj[3][4] = 12;
    adj[4][2] = 2;
    adj[4][5] = 9;
    adj[4][8] = 8;
    adj[5][8] = 3;
    adj[8][5] = 3;
    adj[8][7] = 6;
    adj[7][5] = 4;
    adj[5][7] = 5;
    adj[5][6] = 2;
    adj[6][7] = 1;

    cout << "Adjacency Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adj[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
