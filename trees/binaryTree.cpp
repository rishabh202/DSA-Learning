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

void inorder(node* root){
    // Base case
    if(root == NULL){
      return;
    }

    inorder(root->left);  // L
    cout<<root->data<<" ";  // N
    inorder(root->right);   // R
  
}

void preorder(node* root){
  // Base case
  if(root == NULL){
    return;
  }

  cout<<root->data<<" ";  // N
  preorder(root->left); // L
  preorder(root->right); // R

};
void postorder(node* root){
  // Base case
  if(root == NULL){
    return;
  }

  preorder(root->left); // L
  preorder(root->right); // R
  cout<<root->data<<" ";  // N

};

void buildFromLevelOrder(node* root){
  queue<node*> q;
  cout<<"Enter data for root: "<<endl;
  int data;
  cin>>data;
  root = new node(data);
  q.push(root);

  while (!q.empty())
  {
   node* temp = q.front();
   q.pop();
   cout<<"Enter left node for: "<< temp->data <<endl;
   int leftData;
   cin>>leftData;

   if(leftData != -1){
    temp -> left = new node(leftData);
    q.push(temp->left);
   }

   cout<<"Enter right node for: "<< temp->data <<endl;
   int rightData;
   cin>>rightData;

   if(rightData != -1){
    temp -> right = new node(rightData);
    q.push(temp->right);
   }
  }
  
}



int main(){
    cout<<"Lec 62 | Trees"<<endl;
    node* root = NULL;

    buildFromLevelOrder(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    levelOrderTraversal(root);

  /*
    // Creating a tree 
    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

    // level order
    cout<<"Printing the level order traversal output"<<endl;
    levelOrderTraversal(root);

    cout<<"Inorder traversal is: "<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Preorder traversal is: "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Postorder traversal is: "<<endl;
    postorder(root);
    cout<<endl;

    */

    return 0;
}