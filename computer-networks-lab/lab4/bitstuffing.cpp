#include <iostream>
using namespace std;
  

int main() {
    string arr;
    cout << "Enter bit stream: ";
    cin >> arr;
    int count = 0;
    cout << "After Bit Stuffing: ";
    for (int i = 0; i < arr.length(); i++) {
         cout << arr[i];
         if (arr[i] == '1') {
            count++;
            if (count == 5) {
                cout << '0';
                count = 0;
            }    }
        else {
            count = 0; 
        }
           }
     return 0;
}
