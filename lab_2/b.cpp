#include <iostream>

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

Node* shifted_poem(Node* head, int k){
    Node* cur = head;

    while(k--){
        cur = cur->next;
    }
    return cur;
}

void print(Node* head, int k){
    Node* cur = head;
    Node* secondCur = shifted_poem(head, k);
    while(secondCur != NULL){
        cout << secondCur->word << " ";
        secondCur = secondCur->next;
    }
    while(k--) {
        cout << cur->word << ' ';
        cur = cur->next;
    }
    cout << endl;
}



int main(){
    int n; cin >> n;
    int k; cin >> k;
    Node* head = nullptr;
    Node* cur = nullptr;

    for (int i = 0; i < n; i++)
    {
        string str; cin >> str;
        if(i == 0){
            head = new Node(str);
            cur = head;
        }else{
            cur->next = new Node(str);
            cur = cur->next;
        }
    }
    print(head, k);
}