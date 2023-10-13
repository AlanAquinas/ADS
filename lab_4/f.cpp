#include<iostream>

using namespace std;

int counter = 0;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = left;
        this->right = right; 
    }
};

void insert(Node* &root, int val){
    if(root == NULL){
        root = new Node(val);
        return;
    }else if(root->val > val){
        insert(root->left, val);
    }else{
        insert(root->right, val);
    }
}

void getCountMiniT(Node* root){
    if(root == NULL) return;
    else if(root->left != NULL && root->right != NULL) counter++;
    getCountMiniT(root->left);
    getCountMiniT(root->right);
}

int main(){
    int n; cin >> n;

    Node* root = NULL;

    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        insert(root, k);
    }
    
    getCountMiniT(root);

    cout << counter;
}