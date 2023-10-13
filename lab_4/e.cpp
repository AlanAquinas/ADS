#include<iostream>
#include <algorithm>

using namespace std;

int count_of_node[1000];

struct Node{
    int x;
    Node* left = NULL;
    Node* right = NULL;

    Node(){
        this->left = NULL;
        this->right = NULL;
    }

    Node(int x){
        this->x = x;
        this->left = NULL;
        this->right = NULL;
    }
};

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

void count_Node_by_Level(Node* root, int heightTree){
    if(root == NULL) return;
    count_of_node[heightTree] ++;

    count_Node_by_Level(root->left, heightTree+1); 
    count_Node_by_Level(root->right, heightTree+1); 
}

Node* search(Node* root, int x){
    if(root->x == x || root == NULL) return root;

    else if(root->x > x) search(root->left, x);
    else search(root->right, x);
}

void insert(Node* root, int y, int z){
    if(root == NULL){
        root = new Node(y);
        return;
    } else if(z == 0){
        insert(root->left, y, z);
    } else{
        insert(root->right, y, z);
    }
}

void push(Node* &root, int x, int y, int z){
    Node* found = search(root, x);
    insert(found, y, z); 
}

int main(){
    int n; cin >> n;
    
    Node* root = new Node();

    for (int i = 0; i < n-1; i++)
    {
        int x; cin >> x;
        int y; cin >> y;
        int z; cin >> z;
        push(root, x, y, z);
    }

    int height = getHeight(root);

    count_Node_by_Level(root, 0);

    int max_count_of_node = count_of_node[1];

    for (int i = 2; i < height + 1; i++)
    {
        if(max_count_of_node<count_of_node[i]) max_count_of_node = count_of_node[i];
    }
    

    cout << max_count_of_node;

}