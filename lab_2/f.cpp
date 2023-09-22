#include<iostream>

using namespace std;

struct Node{
    int val;
    Node* next;

    Node(){}

    Node(int newVal){
        this->val = newVal;
        this->next = nullptr; 
    }
};

void insert_node(Node** head, int num, int index){
    Node* new_node = new Node(num);


    if(index == 0){
        new_node->next = *head;
        *head = new_node;
    }else{
        Node* temp = *head;

        while(index-- != 1){
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void print(Node* head){
    Node* cur = head;
    while(cur!=NULL){
        cout << cur->val << " ";
        cur = cur->next;
    }
}

int main(){
    Node* head;
    Node* cur;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        if(i==0){
            head = new Node(k);
            cur = head;
        }else{
            cur->next = new Node(k);
            cur = cur->next;
        }
    }

    int num; cin >> num;
    int index; cin >> index;

    insert_node(&head, num, index);

    print(head);
}