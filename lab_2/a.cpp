#include <iostream>
#include <cstdlib>

struct Node 
{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

int findNearest(Node* head, int k) {
    int nearest = head->data;
    int minDiff = abs(k - head->data);
    
    Node* current = head->next;
    
    while (current) {
        int diff = abs(k - current->data);
        if (diff < minDiff) {
            minDiff = diff;
            nearest = current->data;
        }
        current = current->next;
    }
    
    return nearest;
}

int main() {
    // Create a linked list
    Node* head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(17);

    int k = 16; // The integer to find the nearest to

    int nearest = findNearest(head, k);

    std::cout << "The nearest integer to " << k << " is: " << nearest << std::endl;

    // Clean up memory (not shown: deallocate memory for nodes)
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
