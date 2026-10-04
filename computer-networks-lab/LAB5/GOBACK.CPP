#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int m, totalFrames;

    cout << "Enter number of bits (m): ";
    cin >> m;

    cout << "Enter total frames: ";
    cin >> totalFrames;

    int windowSize = pow(2, m) - 1;

    cout << "\nSender Window Size: " << windowSize;
    cout << "\nReceiver Window Size: 1\n\n";

    int base = 0;

    while (base < totalFrames) {

        int end = min(base + windowSize, totalFrames);

        cout << "Sending frames: ";
        for (int i = base; i < end; i++) {
            cout << i << " ";
        }
        cout << endl;

        int choice;
        cout << "1. Normal ACK\n";
        cout << "2. ACK Lost\n";
        cout << "3. Frame Lost\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "ACK received. Sliding window.\n\n";
            base = end;   // move window forward
        }

        else if (choice == 2) {
            cout << "ACK Lost! Timeout.\n";
            cout << "Resending same window...\n\n";
            // base remains same (retransmit)
        }

        else if (choice == 3) {
            cout << "Frame Lost! Go back and resend all frames.\n\n";
            // base remains same (retransmit whole window)
        }
    }

    cout << "All frames sent successfully.\n";
    return 0;
}

