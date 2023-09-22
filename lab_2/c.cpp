#include<iostream>

using namespace std;

struct Node {
    int val;
    Node *next;

    Node(int newVal) {  
        this->val = newVal;
        this->next = nullptr;
    }
};



int main(){
    int n; cin >> n;
    Node* cur;
    Node* head; 

    for (int i = 0; i < n; i++)
    {
        int val; cin >> val;
        if(!i){
            head = new Node(val); 
            cur = head;
        }else{
            cur->next = new Node(val);
            cur = cur->next;
        }
    }

    while(head != nullptr) {
        cout << head->val << ' ';
        head = head->next;
        if(head == nullptr) {
            break;
        }
        head = head->next;
    }
}