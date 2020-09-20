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
        node(){
            this->data=0;
            this->left=NULL;
            this->right=NULL;
        }
        node* insert(node* root, int data);
};


void printINORDER(node* nd){
    if(nd==NULL)return;

    printINORDER(nd->left);

     cout<<nd->data<<" ";
    
    printINORDER(nd->right);

   
}

node* bstFromPreorder(int* arr, int bound, int* i,int size) {
    if (*i == size || arr[*i] > bound) return NULL;
    node* root = new node(arr[*i]);
    *i=*i+1;
    root->left = bstFromPreorder(arr, root->data,i,size);
    root->right = bstFromPreorder(arr, bound,i,size);
    return root;
}

node* bstFromPreorder(int* arr,int size) {
    int i=0;
    return bstFromPreorder(arr,INT_MAX,&i,size);
}


node* node::insert(node* root, int data){
    if(root==NULL)
        return new node(data);

    if(data > root->data)
        root->right=insert(root->right,data);
    else
        root->left=insert(root->left, data);
    return root;
}


node* search( node* root, int key) 
{ 
    // Base Cases: root is null or key is present at root 
    if (root == NULL ) {
        cout<<"Not found\n";
        return root;
    }
    if(root->data == key){
        cout<<"Found it\n";
        return root;
    }
     
    // Key is greater than root's key 
    if (root->data < key) 
       return search(root->right, key); 
  
    // Key is smaller than root's key 
    return search(root->left, key); 
} 

int main(){
    int pre[] = {10, 5, 1, 7, 40, 50};  
    int size = sizeof( pre ) / sizeof( pre[0] );  
   
    //node *root = bstFromPreorder(pre, size);
    node b;
    node* root = NULL;
    root=b.insert(root,50);
    b.insert(root, 30); 
    b.insert(root, 20);
    b.insert(root, 80); 
    b.insert(root, 40); 
    b.insert(root, 70); 
    b.insert(root, 60); 
    
    cout << "Inorder traversal of the constructed tree: \n";  
    printINORDER(root);  
    cout<<endl;
    cout<<search(root,20)->data<<'\n';

}