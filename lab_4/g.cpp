#include<iostream>

using namespace std;

int max_distance=  0;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(){
        this->left = left;
        this->right = right; 
    }

    Node(int val){
        this->val = val;
        this->left = left;
        this->right = right; 
    }
};

Node* insert(Node* &root, int val){
    if(root == NULL){
        root = new Node(val);
        return;
    }else if(root->val > val){
        root -> left = insert(root -> left, val);
    }else{
        root -> right = insert(root->right, val);
    }
    return root;
}

int getHeight(Node* root)
{
    if(!root) return 0;
 
    return max(getHeight(root -> left), getHeight(root -> right)) +1;
}
 int get_max_distance(Node* root){
    if(root == NULL) return 0;

    int level = getHeight(root -> left) + getHeight(root -> right) + 1;
    int temp = max(get_max_distance(root ->left), get_max_distance(root-> right));
    
    return max(level, temp);
}

int main(){
    int n; cin >> n;

    Node* root = NULL;

    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        insert(root, k);
    }
    cout << get_max_distance(root);
}