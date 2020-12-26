
/**
 *  insertIntoBST
 *  displayBST
 *  search
 *  isBST
 *  takeInput in BST and LL
 *  createTreeFromSortedArr
 *  insertIntoDLL
 *  displayDLL
 *  displayLL
 *  convertDLLtoTree
 *  convertTreeToDLL
 *  convertTreeToLL
 *  getPathToParticularNode
 *  deleteElement
 *  deleteBSTelement
**/
#include <bits/stdc++.h>
using namespace std;

class Node
{
  public:
   int val;
   Node* left;
   Node* right;
   
   Node(int data){
       this->val = data;
       left = NULL;
       right = NULL;
   }
};
class ListNode
{
  public: 
   int val;
   ListNode *next;
  ListNode(int data){
      this -> val = data;
      next = NULL;
  }
};

void deleteBSTelement(Node *,int ,Node* );

void insertIntoBST(Node* &root,int data){
    Node* temp = new Node(data);
    if(root == NULL){
        root = temp;
        return;
    }
   
    if(root -> val > data){
        if(root->left != NULL)
          insertIntoBST(root->left,data);
        else root->left = temp;
    }
    else{
        if(root->right != NULL)
          insertIntoBST(root->right,data);
        else root->right = temp;
    }
}
void displayBST(Node* root){
    if(root == NULL)
      return;
    
    cout<<root->val<<" : ";
    if(root->left != NULL)
      cout<<root->left->val<<",";
    else cout<<"-1"<<",";
    if(root->right != NULL)
      cout<<root->right->val<<endl;
    else cout<<"-1"<<endl;
    
    displayBST(root->left);
    displayBST(root->right);
}
bool search(Node *root,int key){
    if(root == NULL)
        return false;
   
    if(root->val == key)
      return true;
    else if(root -> val > key)
       return search(root->left,key);
    else return search(root->right,key);
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
ListNode* takeInputIntoLL(){
    int data;
    ListNode* head = NULL , *last = NULL;
    while(true){
        cin>>data;
        if(data == -1)
          break;
        ListNode *temp = new ListNode(data);
        if(head == NULL){
            head = temp;
            last = temp;
        }
        else{
            last -> next = temp;
            last = temp;
        }
    }
    return head;
}
bool isBST(Node* root,int& maxi){
    if(root == NULL)
      return true;
    if(isBST(root->left,maxi) == false)
       return false;
    if(root -> val > maxi)
       maxi = root->val;
    else return false;
    if(isBST(root->right,maxi) == false)
       return false;
    return true;
}
Node* createTreeFromSortedArr(vector<int> arr,int si,int ei){
    if(si > ei)
      return NULL;
    
    int index = (si + ei) / 2;
    Node *cur = new Node(arr[index]);
    cur->left = createTreeFromSortedArr(arr,si,index-1);
    cur->right = createTreeFromSortedArr(arr,index+1,ei);
    return cur;
}
Node* insertIntoDLL(){
    int data;
    Node* head = NULL , *last = NULL;
    while(true){
        cin>>data;
        if(data == -1)
          break;
        Node *temp = new Node(data);
        if(head == NULL){
            head = temp;
            last = temp;
        }
        else{
            last -> right = temp;
            temp -> left = last;
            last = temp;
        }
    }
    return head;
}
void displayDLL(Node *head){
     Node *pointer = head;
     while(pointer !=  NULL){
         cout<<pointer->val<<" ";
         pointer = pointer -> right;
     }
     cout<<endl;
}
void displayLL(ListNode *head){
     ListNode *pointer = head;
     while(pointer !=  NULL){
         cout<<pointer->val<<" ";
         pointer = pointer -> next;
     }
     cout<<endl;
}
Node* convertDLLtoTree(Node* head){
    if(head == NULL || head -> right == NULL)
      return head;
    
    Node *slower = head , *faster = head;
    while(faster != NULL && faster -> right != NULL){
         slower = slower -> right;
         faster = faster -> right -> right;
    }
    
    Node *l = slower -> left; 
    Node *r = slower -> right;
    if(l != NULL)
      l -> right = NULL;
    slower -> left = convertDLLtoTree(head);
    
    if(r != NULL)
      r -> left = NULL;
    slower -> right = convertDLLtoTree(r);
    return slower;
}
pair<Node*,Node*> convertTreeToDLL(Node *root){
     if(root == NULL)
       return {NULL , NULL};
     if(root->left == NULL && root->right == NULL)
        return {root , root};
     
     pair<Node* ,Node*> l = convertTreeToDLL(root->left);
     Node *leftHead = l.first;
     Node *leftTail = l.second;
     pair<Node* ,Node*> r = convertTreeToDLL(root->right);
     Node *rightHead = r.first;
     Node *rightTail = r.second;
     
     Node* cur = new Node(root->val);
     
     cur -> left = leftTail;
     if(leftTail != NULL)
       leftTail -> right = cur;
     
     cur -> right = rightHead;
     if(rightHead != NULL)
       rightHead -> left = cur;
     
     
     if(leftHead == NULL) leftHead = cur;
     if(rightTail == NULL) rightTail = cur;
     return {leftHead , rightTail};
}
pair<ListNode*,ListNode*> convertTreeToLL(Node *root){
     if(root == NULL)
       return {NULL , NULL};
     if(root->left == NULL && root->right == NULL){
        ListNode *cur = new ListNode(root->val);
        return {cur , cur};
     }
     
     pair<ListNode* ,ListNode*> l = convertTreeToLL(root->left);
     ListNode *leftHead = l.first;
     ListNode *leftTail = l.second;
     pair<ListNode* ,ListNode*> r = convertTreeToLL(root->right);
     ListNode *rightHead = r.first;
     ListNode *rightTail = r.second;
     
     ListNode* cur = new ListNode(root->val);
     
     if(leftTail != NULL)
       leftTail -> next = cur;
     
     cur -> next = rightHead;
     
     if(leftHead == NULL) leftHead = cur;
     if(rightTail == NULL) rightTail = cur;
     return {leftHead , rightTail};
}
void getPathToParticularNode(Node *root,int key){
     if(root == NULL)
      return;
    cout<<root->val<<" ";
    if(root->val == key)
      return;
    else if(root -> val > key)
        return getPathToParticularNode(root->left,key);
    else return getPathToParticularNode(root->right,key);
}
void deleteElement(Node* root,Node* prev){
     if(root->left == NULL && root->right == NULL){
        if(prev -> left == root)
          prev -> left = NULL;
        else prev -> right = NULL;
        delete(root);
     }
     else if(root->left != NULL && root->right == NULL){
         if(prev->left == root){
             prev -> left = root -> left;
             root -> left = NULL;
             delete(root);
         }
         else{
             prev -> right = root -> left;
             root -> left = NULL;
             delete(root);
         }
     }
     else if(root->left == NULL && root->right != NULL){
         if(prev->left == root){
             prev -> left = root -> right;
             root -> right = NULL;
             delete(root);
         }
         else{
             prev -> right = root -> right;
             root -> right = NULL;
             delete(root);
         }
     }
     else{
         Node *del_r = root -> right;
         while(del_r -> left != NULL)
           del_r = del_r -> left;
         int replacementElement = del_r -> val;
         deleteBSTelement(root,replacementElement,prev);
         root -> val = replacementElement;
     }
}
void deleteBSTelement(Node *root,int key,Node* prev = NULL){
    if(root == NULL)
        return;
   
    if(root->val == key)
      deleteElement(root,prev);
    else if(root -> val > key)
       deleteBSTelement(root->left,key,root);
    else deleteBSTelement(root->right,key,root);
}

int main()
{
    Node* root = NULL;
    root = takeInput();
    displayBST(root);
    cout<<endl;
    deleteBSTelement(root,5);
    displayBST(root);
}
