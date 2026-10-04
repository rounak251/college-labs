#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cout << "Enter number of data bytes: ";
    cin >> n;
vector<string> data(n);
    cout << "Enter data bytes:\n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    cout << "\nAfter Byte Stuffing:\n";
    cout << "DLE STX ";
    for (int i = 0; i < n; i++) {
        if (data[i] == "DLE") {
            cout << "DLE "; 
        } cout << data[i] << " ";
    }cout << "DLE ETX";
    return 0;}
