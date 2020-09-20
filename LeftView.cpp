#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
    public:
        node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};


void printINORDER(node* nd){
    if(nd==NULL)return;

    printINORDER(nd->left);
    
    printINORDER(nd->right);

    cout<<nd->data<<" ";
}

void leftview(node* root, int* mlp,int level){
    if(root==NULL)return;

    if(*mlp < level){
        cout<<root->data<<" ";
        *mlp=level;
    }
    leftview(root->right,mlp,level+1);
    leftview(root->left,mlp,level+1);
    
}

void leftview(node* root){
    int max_level=0;
    int* p = &max_level;
    leftview(root, p, 1);
}

int main(){
    node* root = new node(1); 
    // root->left = new node(10); 
    // root->right = new node(30); 
    // root->right->left = new node(25); 
    // root->right->right = new node(40); 
    // root->right->right->left = new node(96); 
    // root->right->right->right = new node(69); 
    root->left = new node(2); 
    root->right = new node(3); 
    root->left->left = new node(4); 
    root->left->right = new node(5); 
    root->right->left = new node(6); 
    root->right->right = new node(7); 
    root->right->left->right = new node(8);
    leftview(root);
    //printINORDER(root);

}