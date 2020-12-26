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


Node* setOBST(vector<vector<pair<int,int>> > dp,vector<int> key,int l,int r){
    
 
    if(l == r)
        return new Node(key[dp[l][r].second]);
    
    if(l > r)
        return NULL;
        
    int index = dp[l][r].second;
    Node *cur = NULL;
    Node *temp = new Node(key[index]);
    
    cur = temp;
    cur -> left = setOBST(dp,key,l,index-1);
    cur -> right = setOBST(dp,key,index+1,r);
    return cur;
}
void OptimalSearchTree(vector<int> key,vector<int> freq){
    int n = key.size();
	vector<vector<pair<int,int>> > dp(n,vector<pair<int,int>>(n,{0,0}));

	for(int l=0;l<n;l++){
	    for(int i=0;i<n-l;i++){
	        int j = i + l;
	        if(i == j){
	            dp[i][j].first = freq[i];
	            dp[i][j].second = i;
	            continue;
	        }
	        
	        int mini = INT_MAX;
	        int rootNode;
	        for(int rt=i;rt<=j;rt++){
	            if(rt == i){
	                if(mini > dp[rt+1][j].first){
	                  mini = dp[rt+1][j].first;
	                  rootNode = rt;
	                }
	            }
	            else if(rt == j){
	                if(mini > dp[i][rt-1].first){
	                  mini = dp[i][rt-1].first;
	                  rootNode = rt;
	                }
	            }
	            else{
	                if(mini > (dp[rt+1][j].first+dp[i][rt-1].first)){
	                    mini = dp[rt+1][j].first+dp[i][rt-1].first;
	                    rootNode = rt;
	                }
	            }
	        }
	        
	        int sum = 0;
	        for(int k=i;k<=j;k++)
	          sum += freq[k];
	        dp[i][j].first = sum + mini;
	        dp[i][j].second = rootNode;
	    }
	}
	
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++)
	      cout<<"("<<dp[i][j].first<<","<<dp[i][j].second<<")";
	    cout<<endl;
	}
	
	int l = 0;
	int r = n - 1;
	Node* root = setOBST(dp,key,l,r);
	displayBST(root);
}
int main() {
    vector<int> key{12,15,20,25};
	vector<int> freq{4,3,6,2};
	OptimalSearchTree(key,freq);
	return 0;
}

