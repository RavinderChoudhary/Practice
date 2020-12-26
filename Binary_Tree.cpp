#include <bits/stdc++.h>
using namespace std;
class Node
{ 
  public:
    int val;
    Node* left;
    Node* right;
    
   Node(int data){
       this -> val = data;
       left = NULL;
       right = NULL;
   }
};
Node* takeInput(){
    int data;
    cin>>data;
    
    Node* root = new Node(data);
    queue<Node* > q;
    q.push(root);
    while(!q.empty()){
        Node* cur = q.front();
        cin>>data;
        if(data != -1){
          cur->left = new Node(data);
          q.push(cur->left);
        }
        
        cin>>data;
        if(data != -1){
          cur->right = new Node(data);
          q.push(cur->right);
        }
        q.pop();
    }
    return root;
}
int countNode(Node* root){
    if(root == NULL)
       return 0;
    
    return (countNode(root->left) + countNode(root->right) + 1);
}
void preorderTraversal(Node* root){
    if(root == NULL)
      return;
    cout<<root->val<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void inorderTraversal(Node* root){
    if(root == NULL)
      return;
    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}
void postorderTraversal(Node* root){
    if(root == NULL)
      return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->val<<" ";
}
void display(Node* root){
    if(root == NULL)
      return;
    
    cout<<root->val<<" : ";
    if(root->left != NULL)
      cout<<root->left->val<<",";
    else cout<<"-1"<<",";
    if(root->right != NULL)
      cout<<root->right->val<<endl;
    else cout<<"-1"<<endl;
    
    display(root->left);
    display(root->right);
}
int main() {
    Node* root = takeInput();
    cout<<endl;
    display(root);
    cout<<countNode(root)<<endl;
    preorderTraversal(root);
    cout<<endl;
    inorderTraversal(root);
    cout<<endl;
    postorderTraversal(root);
    cout<<endl;
	return 0;
}
