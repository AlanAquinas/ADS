#include<iostream>

using namespace std;

int sum_by_level[1000];

struct Node{
    int val;
    Node* left = NULL;
    Node* right = NULL;

    Node () {
        left = NULL;
        right = NULL;
    }

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void sumLevel(Node* root, int height, int sum_by_level[]){
    if(root == NULL) return;

    sum_by_level[height] += root->val;

    sumLevel(root->left, height + 1, sum_by_level);
    sumLevel(root->right, height + 1, sum_by_level);
}

void insert(Node* &root, int val){
    if(root == NULL){
        root  = new Node(val);
        return;
    }else if(root->val > val){
        insert(root->left, val);
    }else{
        insert(root->right, val);
    }
}

int getHeight(Node* root)
{
    if (root->left == NULL && root->right == NULL)
        return 0;
 
    int left = 0;
    if (root->left != NULL)
        left = getHeight(root->left);
 
    int right = 0;
    if (root->right != NULL)
        right = getHeight(root->right);
 
    return (max(left, right) + 1);
}

int main(){
    int n; cin >> n;

    Node* root = new Node();

    for (int  i = 0; i < n; i++)
    {
        int k; cin >> k;
        insert(root, k);
    }

    int height = getHeight(root);
    sumLevel(root, 0, sum_by_level);
    cout << height << endl;

    for (int i = 1; i <= height; i++)
    {
        cout << sum_by_level[i] << " "; 
    }
    
}