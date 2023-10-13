#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;

    Node(int val){
        this->left = NULL;
        this->left = NULL;
        this->val = val;
    }
};

void insert(Node* &root, int val){
    if(root == nullptr){
        root = new Node(val);
        return;
    } else if(root->val > val){
        insert(root->left, val);
    } else {
        insert(root->right, val);
    }
}

void printSubTree(Node* root){
    if(root == nullptr){
        return;
    } 
    cout << root->val << " ";
    printSubTree(root->left);
    printSubTree(root->right);
}

Node* search(Node* root, int aim){
    if(root == nullptr || root->val == aim){
        return root;
    } if(root->val > aim){
        return search(root->left, aim);
    } else {
        return search(root->right, aim);
    }
}

int main(){
    int n; cin >> n;

    Node* root = NULL;

    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        insert(root, k);
    }

    int aim; cin >> aim;

    search(root, aim);

    Node* found = search(root, aim);

    
    printSubTree(found);
}