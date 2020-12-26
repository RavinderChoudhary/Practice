#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
   int val;
   Node *next;
   Node(int data){
       this->val = data;
       next = NULL;
   }
};

Node* insertNode(Node *root,int data){
    if(root == NULL){
        Node *temp = new Node(data);
        return temp;
    }
    root -> next = insertNode(root->next,data);
    return root;
}

Node * delete_pos(Node *root,int pos){
    if(pos == 1){
        Node *temp = root;
        root = root -> next;
        temp -> next = NULL;
        delete temp;
        return root;
    }
    root -> next = delete_pos(root->next,pos - 1);
}

pair<Node*,Node*> reverseR(Node *root){
    pair<Node* ,Node* > startAndEnd;
    if(root == NULL || root->next == NULL){
      startAndEnd.first = root;
      startAndEnd.second = root;
      return startAndEnd;
    }
    
    Node *temp = root;
    pair<Node*,Node*> p;
    p = reverseR(root->next);
    root = p.first;
    Node *last = p.second;
    temp -> next = NULL;
    last -> next = temp;
    last = temp;
    
    startAndEnd.first = root;
    startAndEnd.second = last;
    return startAndEnd;
}

void display(Node *root){
     Node *pointer = root;
     while(pointer != NULL){
         cout<<pointer -> val<<" ";
         pointer = pointer -> next;
     }
     cout<<endl;
}

Node* reverseI(Node *root){
    Node *prev = NULL;
    Node *cur;
    Node *pointer = root;
    while(pointer != NULL){
        Node *front = pointer -> next;
        cur = pointer;
        if(prev == NULL)
         cur -> next = prev;
        else cur -> next = prev;
        prev = cur;
        pointer = front;
    }
    return cur;
}

int main() {
    Node *root = NULL;
	Node* (*ptr) (Node* ,int );
	ptr = insertNode;
	root = ptr(root,4);
	
    root = (* insertNode) (root , 6);
	display(root);
	root = (* delete_pos) (root , 1);
	display(root);
    root = ((* reverseR) (root)).first;
    display(root);
    root = reverseI(root);
    display(root);
	return 0;
}
