#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a Job
struct Job {
    int id;
    int deadline;
    int profit;
};

// Comparator function to sort jobs according to descending profit
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobScheduling(vector<Job>& jobs, int n) {
    // Step 1: Sort jobs in descending order of profit
    sort(jobs.begin(), jobs.end(), compare);

    // Find maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    // Create a slot array to keep track of free time slots
    vector<int> slot(maxDeadline + 1, -1);

    int totalProfit = 0;
    int countJobs = 0;

    // Step 2: Assign jobs to latest possible slot
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                countJobs++;
                break;
            }
        }
    }

    // Display results
    cout << "Scheduled Jobs: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != -1)
            cout << slot[i] << " ";
    }

    cout << "\nTotal Jobs Done: " << countJobs;
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    int n;

    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter Job ID, Deadline and Profit:\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    jobScheduling(jobs, n);

    return 0;
}
