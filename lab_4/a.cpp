#include<iostream>
#include<string>

using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
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

bool valid(Node *root, string s){
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'L'){
            root = root->left;
            if(root == NULL) return false;
        } else{
            root = root->right;
            if(root == NULL) return false;
        }
    }
    return true;
}

int main(){
    int n; cin >> n;
    int size; cin >> size;

    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        insert(root, k);
    }

    while(size--){
        string s; cin >> s;
        if(valid(root, s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}