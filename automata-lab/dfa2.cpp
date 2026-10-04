#include <iostream>
using namespace std;

int main() {
    string s;
    int state = 0; 
    bool isA = false; 

    cout << "Enter string: ";
    cin >> s;

    if(s.empty()) { 
        cout << "Valid String" << endl; 
        return 0;
    }

    for (char c : s) {
        if (state == 0) { 
            if (c == 'a') { 
                state = 1; 
                isA = true; 
            }
            else if (c == 'b' || c == 'c') {
                state = 1; 
                isA = false;
            }
            else state = 2; 
        }
        else if (state == 1) {
            if (isA) { 
              
                state = 2;
            } 
            else { 
                
                if (c == 'b' || c == 'c')
                    state = 1;
                else
                    state = 2; 
            }
        }
        else { 
            state = 2;
        }
    }

    if (state == 1)
        cout << "Valid String" << endl;
    else
        cout << "Invalid String" << endl;

    return 0;
}
