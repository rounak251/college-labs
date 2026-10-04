#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {

    vector<string> nodes = {"A","B","C","D","E","F"};

    // Distance vectors received
    vector<int> B = {5,0,8,12,6,2};
    vector<int> D = {16,12,6,0,9,10};
    vector<int> E = {7,6,3,9,0,4};

    // Cost from C to neighbors
    int costCB = 6;
    int costCD = 3;
    int costCE = 5;

    cout << "Routing Table for Router C\n";
    cout << "Destination\tNext Hop\tCost\n";

    for(int i=0;i<nodes.size();i++)
    {
        if(nodes[i] == "C")
        {
            cout << "C\t\t-\t\t0\n";
            continue;
        }

        int viaB = costCB + B[i];
        int viaD = costCD + D[i];
        int viaE = costCE + E[i];

        int minCost = viaB;
        string nextHop = "B";

        if(viaD < minCost)
        {
            minCost = viaD;
            nextHop = "D";
        }

        if(viaE < minCost)
        {
            minCost = viaE;
            nextHop = "E";
        }

        cout << nodes[i] << "\t\t" << nextHop << "\t\t" << minCost << endl;
    }

    return 0;
}