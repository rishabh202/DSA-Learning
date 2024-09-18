#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node (int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root){

cout<<"Enter the data for node: "<<endl;
int data; 
cin>>data;
root = new node(data);

  if(data == -1){
    return NULL;
  }

  cout<<"Enter data for inserting in left of "<<data<<endl;
  root->left = buildTree(root->left);
  cout<<"Enter data for inserting in right of "<<data<<endl;
  root->right = buildTree(root->right);
  return root;

}

int main(){
    cout<<"Lec 62 | Trees"<<endl;

    node* root = NULL;
    // Creating a tree 
    root = buildTree(root);

    return 0;
}