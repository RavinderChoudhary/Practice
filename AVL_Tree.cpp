#include <bits/stdc++.h>e 
using namespace std;
 
class Node
{
  public:
   int val;
   int ht;
   Node* left;
   Node* right;
   
   Node(int data){
       this -> val = data;
       this -> ht = 1;
       left = NULL;
       right = NULL;
   }
};
Node *root = NULL;
int height(Node *root) {
	if (root == NULL) 
		return 0;
	return root->ht;
}
int balanceFactor(Node *root) {
	if(root == NULL)
		return 0;
	return height(root->left) - height(root->right);
}
Node *singleRotationRight(Node* &rt){
    Node *pivot = rt -> left;
    rt -> left = pivot -> right;
    pivot -> right = rt;
    rt -> ht = max(height(rt->left) , height(rt->right)) + 1;
    pivot -> ht = max(height(pivot->left) , height(pivot->right)) + 1;
    return pivot;
}
Node* singleRotationLeft(Node* &rt){
    Node *pivot = rt -> right;
    rt -> right = pivot -> left;
    pivot -> left = rt;
    rt -> ht = max(height(rt->left) , height(rt->right)) + 1;
    pivot -> ht = max(height(pivot->right) , rt->ht) + 1;
    return pivot;
}
Node* insertIntoAVL(Node *root, int data) {

	if (root == NULL) {
		Node *temp = new Node(data);
		return temp;
	}

	if(data > root->val) 
		root->right = insertIntoAVL(root->right, data);
    else if(data < root->val) 
		root->left = insertIntoAVL(root->left, data);
	

	root->ht = max(height(root->left), height(root->right)) + 1;

	int bf = balanceFactor(root);

	if (bf > 1 && data < root->left->val)  // Left Left
	  return singleRotationRight(root);

	if (bf < -1 && data > root->right->val)  // Right Right
		return singleRotationLeft(root);

	if (bf > 1 && data > root->left->val)  // Left Right
	{
	    root->left = singleRotationLeft(root->left);
	    return singleRotationRight(root);
	}
		
	if (bf < -1 && data < root->right->val)  // Right Left
	{
	    root->right = singleRotationRight(root->right);
	    return singleRotationLeft(root);
	}
	
	return root;

}
void insert(int data) { root = insertIntoAVL(root, data); }
void displayBST(Node* root){
    if(root == NULL)
      return;
    
    cout<<root->val<<" : ";
    if(root->left != NULL)
      cout<<root->left->val<<" ";
    else cout<<"-1"<<",";
    if(root->right != NULL)
      cout<<root->right->val<<" "<<endl;
    else cout<<"-1"<<endl;
    
    displayBST(root->left);
    displayBST(root->right);
}
Node* deleteNode(Node* root, int key)  {  
      
    if(root == NULL)  // if element is not found
      return root;  
  
    if(key < root->val)  
        root->left = deleteNode(root->left, key);  
  
    else if(key > root->val)  
        root->right = deleteNode(root->right, key);
    else{
            Node * r = root->right;
            if(root->right == NULL){
                Node * l = root->left;
                delete(root);
                root = l;
            }else if(root->left == NULL){
                delete(root);
                root = r;
            }else{
                while(r->left!=NULL) 
                   r = r->left;
                root->val = r->val;
                root->right = deleteNode(root->right, r->val);
            }
    }
    
    if(root == NULL)  
      return root;  
  
    root->ht = 1 + max(height(root->left),height(root->right));  
  
    int bal = balanceFactor(root);  
  
   if(bal>1){
        if(key > root->left->val){
            return singleRotationRight(root);
        }else{
            root->left = singleRotationLeft(root->left);
            return singleRotationRight(root);
        }
    }else if(bal < -1){
        if(key < root->right->val){
            return singleRotationLeft(root);
        }else{
            root->right = singleRotationRight(root->right);
            return singleRotationLeft(root);
        }
    }
  
    return root;  
}

int main()
{
    
    insert(55);
    insert(66);
    insert(77);
    insert(15);
    insert(11);
    
    insert(33);
    insert(22);
    insert(35);
    insert(25);
   
    insert(44);
    insert(88);
    insert(99);
    displayBST(root);
    cout<<endl;
    
    root = deleteNode(root,33);
    displayBST(root);
    return 0;
}
