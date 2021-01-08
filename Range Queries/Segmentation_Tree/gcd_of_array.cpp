#include <bits/stdc++.h>
using namespace std;

void segmentTree(int *tree,vector<int> arr,int si,int li,int index){  //O(n * log(min(a, b)))
    if(si == li){
        tree[index] = arr[si];
        return;
    }
    
    int mid = (si + li)/2;
    segmentTree(tree,arr,si,mid,2*index);
    segmentTree(tree,arr,mid+1,li,2*index+1);
    tree[index] = __gcd(tree[2*index],tree[2*index + 1]);   // log(n)
}
int query(int *tree,int l,int r,int si,int li,int index){  //O(Log n * Log n).
    if(l > li || r < si)
      return 0;
    if(l <= si && r >= li)
      return tree[index];
    
    int mid = (si + li)/2;
    int left = query(tree,l,r,si,mid,2*index);
    int right = query(tree,l,r,mid+1,li,2*index+1);
    return __gcd(left,right);          // long(n)
}
void update(int *tree, int si, int li, int pos, int new_val,int index) {
    if (si == li) {
        tree[index] = new_val;
        return;
    } 
    int mid = (si + li) / 2;
    if (pos <= mid) update(tree, si, mid, pos, new_val,2*index);
    else update(tree, mid+1, li, pos, new_val,2*index+1);
    tree[index] = __gcd(tree[index*2],tree[index*2+1]);
}
int main()
{   
    vector<int> arr{2, 3, 60, 90, 50};
    int n = arr.size();
    int *tree = new int[2*n];
    segmentTree(tree,arr,0,n-1,1);
    
    for(int i=0;i<2*n;i++)
      cout<<tree[i]<<" ";
    cout<<endl;
    cout<<query(tree,1,3,0,n-1,1)<<endl;
    cout<<query(tree,2,4,0,n-1,1)<<endl;
    cout<<query(tree,0,2,0,n-1,1)<<endl;
    //update(tree,0,n-1,2,4,1);
}
