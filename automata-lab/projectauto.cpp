#include <bits/stdc++.h>
using namespace std;



struct State {
    int id;
    map<char, vector<State*>> trans;
};

struct NFA {
    State* start;
    State* end;
};

int stateCount = 0;

State* newState() {
    State* s = new State();
    s->id = stateCount++;
    return s;
}



NFA createBasic(char c) {
    State* s = newState();
    State* e = newState();
    s->trans[c].push_back(e);
    return {s, e};
}



NFA concatenate(NFA a, NFA b) {
    a.end->trans['e'].push_back(b.start);
    return {a.start, b.end};
}

NFA unite(NFA a, NFA b) {
    State* s = newState();
    State* e = newState();

    s->trans['e'].push_back(a.start);
    s->trans['e'].push_back(b.start);

    a.end->trans['e'].push_back(e);
    b.end->trans['e'].push_back(e);

    return {s, e};
}

NFA kleeneStar(NFA a) {
    State* s = newState();
    State* e = newState();

    s->trans['e'].push_back(a.start);
    s->trans['e'].push_back(e);

    a.end->trans['e'].push_back(a.start);
    a.end->trans['e'].push_back(e);

    return {s, e};
}



string addConcat(string regex) {
    string result = "";

    for (int i = 0; i < regex.size(); i++) {
        char c1 = regex[i];
        result += c1;

        if (i + 1 < regex.size()) {
            char c2 = regex[i + 1];

            if ((isalnum(c1) || c1 == '*' || c1 == ')') &&
                (isalnum(c2) || c2 == '(')) {
                result += '.';
            }
        }
    }
    return result;
}



int precedence(char c) {
    if (c == '*') return 3;
    if (c == '.') return 2;
    if (c == '|') return 1;
    return 0;
}

string toPostfix(string regex) {
    stack<char> st;
    string output = "";

    for (char c : regex) {
        if (isalnum(c)) {
            output += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                output += st.top(); st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                output += st.top(); st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        output += st.top(); st.pop();
    }

    return output;
}



NFA buildNFA(string postfix) {
    stack<NFA> st;

    for (char c : postfix) {
        if (isalnum(c)) {
            st.push(createBasic(c));
        }
        else if (c == '.') {
            NFA b = st.top(); st.pop();
            NFA a = st.top(); st.pop();
            st.push(concatenate(a, b));
        }
        else if (c == '|') {
            NFA b = st.top(); st.pop();
            NFA a = st.top(); st.pop();
            st.push(unite(a, b));
        }
        else if (c == '*') {
            NFA a = st.top(); st.pop();
            st.push(kleeneStar(a));
        }
    }

    return st.top();
}



set<State*> epsilonClosure(set<State*> states) {
    stack<State*> st;
    for (auto s : states) st.push(s);

    while (!st.empty()) {
        State* s = st.top(); st.pop();

        for (auto nxt : s->trans['e']) {
            if (!states.count(nxt)) {
                states.insert(nxt);
                st.push(nxt);
            }
        }
    }
    return states;
}

/* ===================== MOVE FUNCTION ===================== */

set<State*> move(set<State*> states, char c) {
    set<State*> result;

    for (auto s : states) {
        for (auto nxt : s->trans[c]) {
            result.insert(nxt);
        }
    }
    return result;
}

/* ===================== NFA TO DFA ===================== */

void convertToDFA(NFA nfa) {
    map<set<State*>, int> dfa;
    queue<set<State*>> q;

    set<State*> start = epsilonClosure({nfa.start});
    q.push(start);
    dfa[start] = 0;

    int id = 1;

    cout << "\n--- DFA TRANSITIONS ---\n";

    while (!q.empty()) {
        auto curr = q.front(); q.pop();

        for (char c = 'a'; c <= 'z'; c++) {
            auto next = epsilonClosure(move(curr, c));
            if (next.empty()) continue;

            if (!dfa.count(next)) {
                dfa[next] = id++;
                q.push(next);
            }

            cout << "D" << dfa[curr] << " --" << c
                 << "--> D" << dfa[next] << endl;
        }
    }
}

/* ===================== MAIN ===================== */

int main() {
    string regex;

    cout << "Enter Regular Expression: ";
    cin >> regex;

    string withConcat = addConcat(regex);
    string postfix = toPostfix(withConcat);

    cout << "\nPostfix Expression: " << postfix << endl;

    NFA nfa = buildNFA(postfix);

    convertToDFA(nfa);

    return 0;
}