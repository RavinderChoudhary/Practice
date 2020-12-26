


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
    cout<<"Enter the number of children"<<endl;
    cin>>n;
    Node<int> *temp = new Node<int>(data);
    for(int i=0;i<n;i++)
     temp->children.push_back(takeInput());
    return temp;
}
void display(Node<int>* root){
    cout<<root->val<<": ";
    for(int i=0;i<root->children.size();i++)
       cout<<root->children[i]->val<<" ";
    cout<<endl;
    for(int i=0;i<root->children.size();i++)
       display(root->children[i]);
}
int main() {
	Node<int> *root = takeInput();
	display(root);
	return 0;
}
