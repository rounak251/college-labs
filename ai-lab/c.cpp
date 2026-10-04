#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

void printState(string state) {
    for (int i = 0; i < 9; i++) {
        cout << state[i] << " ";
        if (i % 3 == 2)
            cout << endl;
    }
    cout << endl;
}

vector<string> generateStates(string state) {
    vector<string> nextStates;
    int pos = state.find('0');   // position of blank
    int row = pos / 3;
    int col = pos % 3;

    int dx[] = {-1, 1, 0, 0};  // up, down
    int dy[] = {0, 0, -1, 1}; // left, right

    for (int i = 0; i < 4; i++) {
        int newRow = row + dx[i];
        int newCol = col + dy[i];

        if (newRow >= 0 && newRow < 3 && newCol >= 0 && newCol < 3) {
            string newState = state;
            swap(newState[pos], newState[newRow * 3 + newCol]);
            nextStates.push_back(newState);
        }
    }
    return nextStates;
}

void bfs(string start, string goal) {
    queue<string> q;
    unordered_set<string> visited;
    unordered_map<string, string> parent;

    q.push(start);
    visited.insert(start);
    parent[start] = "";

    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        if (curr == goal)
            break;

        for (string next : generateStates(curr)) {
            if (!visited.count(next)) {
                visited.insert(next);
                parent[next] = curr;
                q.push(next);
            }
        }
    }

    // Print solution path
    vector<string> path;
    for (string s = goal; s != ""; s = parent[s])
        path.push_back(s);

    cout << "BFS Solution:\n";
    for (int i = path.size() - 1; i >= 0; i--)
        printState(path[i]);
}

void dfs(string start, string goal) {
    stack<string> st;
    unordered_set<string> visited;
    unordered_map<string, string> parent;

    st.push(start);
    visited.insert(start);
    parent[start] = "";

    while (!st.empty()) {
        string curr = st.top();
        st.pop();

        if (curr == goal)
            break;

        for (string next : generateStates(curr)) {
            if (!visited.count(next)) {
                visited.insert(next);
                parent[next] = curr;
                st.push(next);
            }
        }
    }

    vector<string> path;
    for (string s = goal; s != ""; s = parent[s])
        path.push_back(s);

    cout << "DFS Solution:\n";
    for (int i = path.size() - 1; i >= 0; i--)
        printState(path[i]);
}

int main() {
    string initial = "123405678";
    string goal = "123456780";

    bfs(initial, goal);
    cout << "-----------------------\n";
    dfs(initial, goal);

    return 0;
}