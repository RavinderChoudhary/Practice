

#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Node
{
  public:
   T val;
   vector<Node<T>*> children;
   Node(T data){
       this -> val = data;
   }
};


Node<int>* takeInput(){
    int data,n;

    cout<<"Enter the value of root"<<endl;
    cin>>data;

    queue<Node<int>* > q;
    Node<int> *root = new Node<int>(data);
    q.push(root);

    while(!q.empty()){
      Node<int>* cur = q.front();
      cout<<"Enter the number of children of : "<<cur->val<<endl;
      cin>>n;
       for(int i=0;i<n;i++){
         cout<<"Enter the val";
         cin>>data;
         Node<int>* child = new Node<int>(data);
         cur->children.push_back(child);
         q.push(child);
       }
      q.pop();
     }
    return root;
}
void display(Node<int>* root){
    cout<<root->val<<": ";
    for(int i=0;i<root->children.size();i++)
       cout<<root->children[i]->val<<" ";
    cout<<endl;
    for(int i=0;i<root->children.size();i++)
       display(root->children[i]);
}
int countNode(Node<int>* root){
    if(root->children.size() == 0)
       return 1;
    
    int counter = 0;
    for(int i=0;i<root->children.size();i++)
      counter += countNode(root->children[i]);
    return counter + 1;
}
int heightOfTree(Node<int>* root){
    if(root->children.size() == 0)
       return 0;
    
    int maxi = INT_MIN;
    for(int i=0;i<root->children.size();i++)
      maxi = max(maxi,heightOfTree(root->children[i]));
    return maxi + 1;
}
void printTheDepth(Node<int>* root,int k){
    if(k == 0){
        cout<<root->val<<" ";
        return;
    }
    
    for(int i=0;i<root->children.size();i++)
       printTheDepth(root->children[i],k-1);
}
int countLeafNodes(Node<int>* root){
    if(root->children.size() == 0)
      return 1;
    
    int counter = 0;
    for(int i=0;i<root->children.size();i++)
       counter += countLeafNodes(root->children[i]);
    return counter;
}
void preOrderTraversal(Node<int>* root){ // DLR
        cout<<root->val<<" ";
     
     for(int i=0;i<root->children.size();i++)
       preOrderTraversal(root->children[i]);
}
void postOrderTraversal(Node<int>* root){ // LRD
        
     for(int i=0;i<root->children.size();i++)
       postOrderTraversal(root->children[i]);
       
     cout<<root->val<<" ";
}
void deleteTree(Node<int>* root){
    for(int i=0;i<root->children.size();i++)
       deleteTree(root->children[i]);
    delete root;
}
int main() {

	Node<int>* root = takeInput();
	display(root);
	cout<<"Count Total Nodes : "<<countNode(root)<<endl;
	cout<<"Height of Tree : "<<heightOfTree(root)<<endl;
	printTheDepth(root,2);
	cout<<endl;
	cout<<"countLeafNodes : "<<countLeafNodes(root)<<endl;
	preOrderTraversal(root);
	cout<<endl;
	postOrderTraversal(root);
	deleteTree(root);
	return 0;
}
// 1 3 2 3 4 2 5 6 0 1 9 0 2 7 8 0 0 0
