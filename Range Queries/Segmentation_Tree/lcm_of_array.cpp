#include <bits/stdc++.h>
using namespace std;
int lcm(int a,int b){
    return (a*b)/__gcd(a,b);
}
void segmentTree(int *tree,vector<int> arr,int si,int li,int index){
    if(si == li){
        tree[index] = arr[si];
        return;
    }
    
    int mid = (si + li)/2;
    segmentTree(tree,arr,si,mid,2*index);
    segmentTree(tree,arr,mid+1,li,2*index+1);
    tree[index] = lcm(tree[2*index],tree[2*index + 1]);
}
int query(int *tree,int l,int r,int si,int li,int index){
    if(l > li || r < si)
      return 1;
    if(l <= si && r >= li)
      return tree[index];
    
    int mid = (si + li)/2;
    int left = query(tree,l,r,si,mid,2*index);
    int right = query(tree,l,r,mid+1,li,2*index+1);
    return lcm(left,right);
}
void update(int *tree, int si, int li, int pos, int new_val,int index) {
    if (si == li) {
        tree[index] = new_val;
        return;
    } 
    int mid = (si + li) / 2;
    if (pos <= mid) update(tree, si, mid, pos, new_val,2*index);
    else update(tree, mid+1, li, pos, new_val,2*index+1);
    tree[index] = lcm(tree[index*2],tree[index*2+1]);
}
int main()
{   
    vector<int> arr{5, 7, 5, 2, 10, 12 ,11, 17, 14, 1, 44};
    int n = arr.size();
    int *tree = new int[2*n];
    segmentTree(tree,arr,0,n-1,1);
    
    for(int i=0;i<2*n;i++)
      cout<<tree[i]<<" ";
    cout<<endl;
    cout<<query(tree,5,10,0,n-1,1)<<endl;
    cout<<query(tree,0,10,0,n-1,1)<<endl;
    //update(tree,0,n-1,2,4,1);
}
