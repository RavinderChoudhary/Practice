#include <bits/stdc++.h>
using namespace std;
 
class Node
{
  public:
   int val;
   Node* left;
   Node* right;
   bool isThreaded;
   
   Node(int data){
       this->val = data;
       left = NULL;
       right = NULL;
       this -> isThreaded = false;
   }
};
 
void InsertIntoQueue(Node *root, std::queue <Node *> &q)
{
    if (root == NULL) return;
    if (root->left != NULL)
        InsertIntoQueue(root->left, q);
    q.push(root);
    if (root->right != NULL)
        InsertIntoQueue(root->right, q);
}
 
void ThreadedTree(Node *root, std::queue <Node *> &q)
{
	if (root == NULL) 
        return; 
  
    if (root->left) 
        ThreadedTree(root->left, q); 
    q.pop(); 
  
    if (root->right) 
        ThreadedTree(root->right, q); 
    else { 
        if(!q.empty())
          root->right = q.front(); 
        root->isThreaded = true; 
    } 
}
 
Node *leftMost(Node *root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}
 
void printInorderTraversal(Node *root)
{
    if (root == NULL) 
      return;
 
    Node *cur = leftMost(root);
 
    while (cur != NULL)
    {
        cout << cur->val << " ";
 
        if (cur->isThreaded)
            cur = cur->right;
        else  cur = leftMost(cur->right);
    }
}
 
 
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

int main()
{
    Node *root = takeInput();
    queue <Node *> q;
    InsertIntoQueue(root, q);
    ThreadedTree(root, q);
    printInorderTraversal(root);
    return 0;
}
