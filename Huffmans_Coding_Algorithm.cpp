#include <bits/stdc++.h>
using namespace std;
 
class Node
{
  public:
   int val;
   char ch;
   Node* left;
   Node* right;
   
   Node(int data,int ch){
       this -> val = data;
       this -> ch = ch;
       left = NULL;
       right = NULL;
   }
};
struct compare
{
  bool operator()(Node* n1,Node* n2){
      return n1->val > n2->val;
  }  
};
void displayBST(Node* root){
    if(root == NULL)
      return;
    
    cout<<"("<<root->ch<<","<<root->val<<")"<<" : ";
    if(root->left != NULL)
      cout<<"("<<root->left->ch<<","<<root->left->val<<") ";
    else cout<<"-1"<<",";
    if(root->right != NULL)
      cout<<"("<<root->right->ch<<","<<root->right->val<<")"<<endl;
    else cout<<"-1"<<endl;
    
    displayBST(root->left);
    displayBST(root->right);
}
void encodeChar(Node* root,string s,unordered_map<char,string> &binaryRepresentation){
     if(root == NULL)
       return;
     if(root->left == NULL && root->right == NULL){
         binaryRepresentation.insert({root->ch,s});
         return;
     }
     encodeChar(root->left,s + '0',binaryRepresentation);
     encodeChar(root->right,s + '1',binaryRepresentation); 
}
void decodeChar(Node* root,int index,string encodeChar,int &nextIndex){
    if(root == NULL)
      return;
    if(root->left == NULL && root->right == NULL){
        cout<<root->ch;
        nextIndex = index - 1;
        return;
    }
    
    if(encodeChar[index] == '0')
      decodeChar(root->left,index+1,encodeChar,nextIndex);
    else decodeChar(root->right,index+1,encodeChar,nextIndex);
}
int main()
{
    string str = "Ravinder is Great";
    unordered_map<char,int> mp;
    for(char ch : str)
      mp[ch]++;
    priority_queue<Node* , vector<Node*> , compare> pq;
    for(auto it : mp){
        int data = it.second;
        char ch = it.first;
        pq.push(new Node(data,ch));
    }
    while(pq.size() != 1){
        Node* cur1 = pq.top();  pq.pop();
        Node* cur2 = pq.top();  pq.pop();
        Node *cur = new Node(cur1->val + cur2->val,'/');
        cur -> left = cur1;
        cur -> right = cur2;
        pq.push(cur);
    }
    
    unordered_map<char,string> binaryRepresentation;
    encodeChar(pq.top(),"",binaryRepresentation);
    
    string encodedStr;
    for(char ch : str)
      encodedStr += binaryRepresentation[ch];
    
    cout<<encodedStr<<endl;
    
    int nextIndex;
    for(int index=0;index < encodedStr.length();index++){
      nextIndex = index;
      decodeChar(pq.top(),index,encodedStr,nextIndex);
      index = nextIndex;
    }
    return 0;
}
