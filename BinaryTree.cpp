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

int main(){
    node* root = new node(1);
    root->left = new node(2); 
    root->right = new node(3); 
    root->left->left = new node(4); 
    root->left->right = new node(5);
    printINORDER(root);

}