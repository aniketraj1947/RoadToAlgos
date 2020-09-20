#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    public:
    node(int data);
    node();
};

node::node(int data){
    this->data=data;
    this->left=NULL;
    this->right=NULL;
}

node::node(){
    this->data = 0;
    this->left=NULL;
    this->right=NULL;
}


// Node* insertLevelOrder(int arr[], Node* root, 
//                        int i, int n) 
// { 
//     // Base case for recursion 
//     if (i < n) 
//     { 
//         Node* temp = newNode(arr[i]); 
//         root = temp; 
  
//         // insert left child 
//         root->left = insertLevelOrder(arr, 
//                    root->left, 2 * i + 1, n); 
  
//         // insert right child 
//         root->right = insertLevelOrder(arr, 
//                   root->right, 2 * i + 2, n); 
//     } 
//     return root; 
// } 

bool isPresent(node* root,node* x){
    if(root == NULL)
        return false;
    if(root == x)
        return true;
    return (isPresent(root->right,x) || isPresent(root->left,x));
}

void preorder(node* root){
    if(root == NULL)return;

    cout<<root->data<<" ";

    preorder(root->left);
    preorder(root->right);
}

node* lca(node* root, node* x, node* y){
    if(root == NULL)
        return NULL;
    if(root == x || root ==y)
        return root;
    
    node* left = lca(root->left,x,y);
    node* right = lca(root->right,x,y);

    if(left && right)
        return root; 
    if(left)
        return left;
    if(right)
        return right;
    return NULL;
}

int level(node* root, node* x, int curr){
    if(root == NULL)
        return INT_MIN;
    if(root == x)
        return curr;
    
    int left = level(root->left,x,curr+1);

    if(left!=INT_MIN)
        return left;

    return level(root->right,x,curr+1);
}


int main(){
    node* root = new node(20);
    root->right = new node(30);
    root->left = new node(60);
    root->right->right = new node(70);
    root->right->left = new node(10);
    //preorder(root);
    node* lca2 = lca(root, root->right->left, root->left);
    cout<<level(lca2,root->left,0)+level(lca2,root->right->left,0)<<endl;
}

//distance b/w 2 nodes is levelA-LCALEVEL + levelB-LCALEVEL