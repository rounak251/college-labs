#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool simulateLoss() {
    return rand() % 4 == 0;  // 25% chance of loss
}

int main() {
    srand(time(0));
    
    int totalFrames;
    cout << "Enter number of frames to send: ";
    cin >> totalFrames;

    int seq = 0;

    for (int i = 0; i < totalFrames; i++) {
        while (true) {
            cout << "\nSender: Sending Frame " << i 
                 << " with Seq No: " << seq << endl;

            if (simulateLoss()) {
                cout << "Frame Lost! Resending...\n";
                continue;
            }

            cout << "Receiver: Frame " << i 
                 << " received. Sending ACK...\n";

            if (simulateLoss()) {
                cout << "ACK Lost! Resending Frame...\n";
                continue;
            }

            cout << "Sender: ACK received.\n";
            seq = 1 - seq;   // Toggle between 0 and 1
            break;
        }
    }

    cout << "\nAll Frames Sent Successfully!\n";
    return 0;
}
