#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;

    Node(int newValue){
        this -> value = newValue;
        this -> next = NULL;
    }
};

void print(Node* head) {
  Node* cur = head;
  while (cur != NULL) {
    cout << cur->value << " ";
    cur = cur->next;
  }
  cout << endl;
}

void nearestNumber(Node* head, int nearest){
    Node* cur = head;
    int result = 0;
    int index = 0;

    int min = abs(nearest - head->value);
    while(cur != NULL){
        if(min > abs(nearest - cur->value)){
            min = abs(nearest - cur->value);
            result = index;
        }
        cur = cur->next;
        index++;
    }
    cout << result << endl;
}

int main(){
    int n; cin >> n;
    Node *head;
    Node *a;
    Node *cur;

    for (int i = 0; i < n; i++)
    {
        int value; cin >> value;
        if (i==0)
        {
            head = new Node(value);
            cur = head;
        } else {
            a = new Node(value);
            cur -> next = a;
            cur = cur -> next;
        }
    }

    int nearest; cin >> nearest;
    
    nearestNumber(head, nearest);
}
