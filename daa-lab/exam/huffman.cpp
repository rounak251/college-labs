#include <iostream>
#include <queue>
using namespace std;

struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char d, int f) {
        data = d;
        freq = f;
        left = right = NULL;
    }
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void printCodes(Node* root, string str) {
    if (!root) return;

    if (root->data != '$')
        cout << root->data << ": " << str << endl;

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

int main() {
    char arr[] = {'A','B','C','D','E','F'};
    int freq[] = {5,9,12,13,16,45};
    int n = 6;

    priority_queue<Node*, vector<Node*>, compare> pq;

    for (int i = 0; i < n; i++)
        pq.push(new Node(arr[i], freq[i]));

    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        Node *top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        pq.push(top);
    }

    printCodes(pq.top(), "");
    return 0;
}
