#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    Job jobs[] = {
        {1,2,100},
        {2,1,19},
        {3,2,27},
        {4,1,25},
        {5,3,15}
    };

    int n = 5;

    sort(jobs, jobs+n, compare);

    int maxDeadline = 3;
    int slot[3] = {0};
    int totalProfit = 0;

    for(int i=0; i<n; i++) {
        for(int j=jobs[i].deadline-1; j>=0; j--) {
            if(slot[j] == 0) {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Selected Jobs: ";
    for(int i=0; i<3; i++)
        if(slot[i] != 0)
            cout << "J" << slot[i] << " ";

    cout << "\nTotal Profit: " << totalProfit;

    return 0;
}
