#include<iostream>
#include<queue>
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

};

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
      node* temp = q.front();
      q.pop();

      if (temp == NULL){  // If temp = NULL, then it means last level is fully traversed. 
      cout<<endl;
      if(!q.empty()){
          q.push(NULL);
      };

      }
      else{
        cout<< temp->data<<" ";
        if(temp->left){
        q.push(temp->left);

      };

      if(temp->right){
        q.push(temp->right);

      };
      }

      
    };
    

};

int main(){
    cout<<"Lec 62 | Trees"<<endl;

    node* root = NULL;

    // Creating a tree 
    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

    // level order
    cout<<"Printing the level order traversal output"<<endl;
    levelOrderTraversal(root);

    return 0;
}