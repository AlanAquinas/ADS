#include<iostream>

using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    
    Node(int val){
        this->left = NULL;
        this->right = NULL;
        this->val = val;
    }
};

void insert(Node* &root, int val){
    if(root==NULL){
        root = new Node(val);
        return;
    } else if(root->val > val){
        insert(root->left, val);
    } else{
        insert(root->right, val);
    }
}

int countNodes(Node* root) {
    if (root == nullptr) return 0; 

    return 1 + countNodes(root->left) + countNodes(root->right);
}

void foundNode(Node* root, int aim){
    if (root->val == aim) {
        cout << countNodes(root);
    }
    else if(root->val > aim){
        foundNode(root->left, aim);
    }else{
        foundNode(root->right, aim);
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

    foundNode(root, aim);
}