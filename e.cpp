#include <iostream>
#include <map>
#include <set>

using namespace std;

set<string> st;

struct Node{
    string val;
    Node* next;

    Node(){}

    Node(string newVal){
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

void unique_students(Node* head){
    Node* cur = head;
    while (cur!=NULL)
    {
        st.insert(cur->val);
        cur = cur->next;
    }
}

int main(){
    int n; cin >> n;
    Node *cur;
    Node *head;

    for (int i = 0; i < n; i++)
    {
        string k; cin >> k;
        if(i == 0){
            head = new Node(k);
            cur = head;
        }else{
            cur->next = new Node(k);
            cur = cur->next;
        }
    }

    unique_students(head);

    cout << "All in all: " << st.size() << endl;
    cout << "Students:" << endl;

    for (auto& i : st) {
        cout << i << endl;
    }
}