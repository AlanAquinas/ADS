#include <iostream>
#include <string>

using namespace std;

struct Node{
    string val;
    Node* next;

    Node(){}

    Node(string newVal){
        this->val = newVal;
        this->next = nullptr;
    }
}; 

void push(struct Node** head_ref, string new_data)
{
    // Allocate node
    struct Node* new_node = new Node();
 
    // Put in the data
    new_node->val = new_data;
 
    // Link the old list of the
    // new node
    new_node->next = (*head_ref);
 
    // Move the head to point to
    // the new node
    (*head_ref) = new_node;
}

void print(Node* head){
    Node* cur = head;
    while(cur!=NULL){
        cout << cur->val << endl;
        cur = cur->next;
    }
    cout << endl;
}

void delete_dublicates(Node* head){
    Node* ptr1 = head;
    Node* ptr2;
    Node* dup;

    while (ptr1 != NULL && ptr1->next != NULL){
        ptr2 = ptr1;
        while(ptr2->next != NULL ){
            if(ptr1->val == ptr2->next->val){
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else{
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

int get_size(Node* head){
    int counter = 0;
    Node* cur = head;

    while(cur!=NULL){
        counter++;
        cur = cur->next;
    }
    return counter;
}

int main(){
    int n; cin >> n;
    Node *head = NULL;
    for (int i = 0; i < n; i++) {
        char val[1000];
        scanf("%s", val);
        
        push(&head, val);
    }

    delete_dublicates(head);

    cout << "All in all: " << get_size(head) << endl;
    cout << "Students:" << endl;

    print(head);
}