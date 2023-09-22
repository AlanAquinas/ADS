#include <bits/stdc++.h>

using namespace std;

struct Node {
    string word;
    Node *next;

    Node() {}

    Node(string newWord){
        this->word = newWord;
        this->next = NULL;
    }
};

int main() {
    int n, k;

    cin >> n >> k;
    Node* head = nullptr;
    Node* cur = nullptr;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (!i) {
            head = new Node(s);
            cur = head;
        } else {
            cur->next = new Node(s);
            cur = cur->next;
        }
        if (i == n - 1) {
            cur->next = head;
            cur = cur->next;
        }
    }

    while (k--) {
        cur = cur -> next;
    }
    for(int i = 0; i < n; i++) {
        cout << cur->word << ' ';
        cur = cur->next;
    }
}