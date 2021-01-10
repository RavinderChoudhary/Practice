// Count elements which divide all numbers in range L-R
// https://www.geeksforgeeks.org/count-elements-which-divide-all-numbers-in-range-l-r/

#include <bits/stdc++.h>
using namespace std;

struct node{
   int gcd;
   int mn;
   int cnt;
};
void buildtree(int si,int ei,int idx,vector<int> a,vector<node>& tree){
     if(si == ei){
         tree[idx].gcd = a[si];
         tree[idx].mn = a[si];
         tree[idx].cnt = 1;
         return;
     }
     
     int mid = (si + ei)/2;
     buildtree(si,mid,2*idx+1,a,tree);
     buildtree(mid+1,ei,2*idx+2,a,tree);
     
     
     tree[idx].gcd = __gcd(tree[2*idx+1].gcd,tree[2*idx+2].gcd);
     
     /**
      *   assign gcd
      *   compare min and assign (min and count)
     * */
     if(tree[2*idx+1].mn < tree[2*idx+2].mn){
        tree[idx].mn = tree[2*idx+1].mn;
        tree[idx].cnt = tree[2*idx+1].cnt;
     }
     else if(tree[2*idx+1].mn > tree[2*idx+2].mn){
        tree[idx].mn = tree[2*idx+2].mn;
        tree[idx].cnt = tree[2*idx+2].cnt;
     }
     else{
        tree[idx].mn = tree[2*idx+1].mn;
        tree[idx].cnt = tree[2*idx+1].cnt + tree[2*idx+2].cnt; 
     }
}
node answerQuery(int si,int ei,vector<int> a,vector<node> &tree,int l,int r,int idx){
    node tmp;
    if(r < si || ei < l){
        tmp.gcd = 0;
        tmp.mn = 0;
        tmp.cnt = 0;
        return tmp;
    }
    
    if(si >= l && r >= ei){   //  Important
        tmp.gcd = tree[idx].gcd;
        tmp.mn = tree[idx].mn;
        if(tmp.gcd != tmp.mn) tmp.cnt = 0;    // gcd != min   ans = 0
        else tmp.cnt = tree[idx].cnt;
    
        return tmp;
    }
    
    int mid = (si + ei)/2;
    node left = answerQuery(si,mid,a,tree,l,r,2*idx+1);
    node right = answerQuery(mid+1,ei,a,tree,l,r,2*idx+2);
    
    if(left.gcd != 0 && right.gcd != 0){
        /**
         * assign  gcd , min
         * count = 0,left,right,left+right
         **/
        tmp.gcd = __gcd(left.gcd, right.gcd); 
        tmp.mn = min(left.mn, right.mn); 
   
        if(tmp.gcd != tmp.mn)          
            tmp.cnt = 0;         
        else 
        { 
            if(left.mn == right.mn)              
                tmp.cnt = left.cnt + right.cnt;             
            else if (left.mn < right.mn)              
                tmp.cnt = left.cnt;             
            else  tmp.cnt = right.cnt;             
        } 
    }
    else if(left.gcd != 0) return left;
    else if(right.gcd != 0) return right;
    return tmp;
}
int main() {
	vector<int> a = { 3, 4, 2, 2, 4, 6 }; 
  
    int n = a.size(); 
    vector<node> tree(5*n);
    buildtree(0, n - 1, 0, a,tree); 
    
    int l = 0, r = 3; 
    cout << answerQuery(0,n-1,a,tree, l, r,0).cnt << endl; 
    l = 1, r = 5; 
    cout << answerQuery(0,n-1,a,tree, l, r,0).cnt << endl; 
	return 0;
}
