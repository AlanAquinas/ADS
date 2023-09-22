#include <iostream>
#include <map>

using namespace std;

int max_count = 0;
map<int, int> m;

struct Node{
    int val;
    Node* next;

    Node(){}

    Node(int newVal){
        this->val = newVal;
        this->next = nullptr;
    }
};

void print(Node* head){
    Node* cur = head;
    while(cur!=NULL){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

void mode(Node* head){
    Node* cur = head;
    while (cur!=NULL){
        max_count = max(max_count, m[cur->val]);
        m[cur->val]++;
        cur = cur->next;
    }
}

int main(){
    int n; cin >> n;
    Node *cur;
    Node *head;

    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        if(i == 0){
            head = new Node(k);
            cur = head;
        }else{
            cur->next = new Node(k);
            cur = cur->next;
        }
    }

    mode(head);

    map <int, int>::reverse_iterator it = m.rbegin();

    for(it; it != m.rend(); it++) {
        if(it->second == max_count+1) {
            cout << it->first<< " ";
        }
    }
}