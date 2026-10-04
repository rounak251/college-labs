#include <iostream>
#include <vector>
using namespace std;

int hammingDistance(string a, string b) {
    int dist = 0;
    for (int i = 0; i < a.length(); i++) {
         if ((a[i] ^ b[i]) == 1)
            dist++;
    }
    return dist;
} 

int main() {
    vector<pair<string, string>> pairs = {
        {"00000", "01011"},
        {"00000", "10101"},
        {"01011", "10101"},
        {"01011", "11110"},
        {"00000", "11110"},             
        {"10101", "11110"}
    };
int minDist = 100;
    for (auto p : pairs) {
        int d = hammingDistance(p.first, p.second);
        cout << "d(" << p.first << ", " << p.second << ") = " << d << endl;
        minDist = min(minDist, d);
    }
cout << "Minimum Hamming Distance = " << minDist << endl;
    return 0;
}
