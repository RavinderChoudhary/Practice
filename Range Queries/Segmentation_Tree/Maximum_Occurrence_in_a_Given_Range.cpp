// https://www.geeksforgeeks.org/maximum-occurrence-given-range/

#include <bits/stdc++.h>
using namespace std;
void segmentTree(vector<int> &tree,vector<int> arr,int si,int li,int index){
    if(si == li){
        tree[index] = arr[si];
        return;
    }
    
    int mid = (si + li)/2;
    segmentTree(tree,arr,si,mid,2*index+1);
    segmentTree(tree,arr,mid+1,li,2*index+2);
    tree[index] = max(tree[2*index+1],tree[2*index+2]);
}
int query(vector<int> tree,int l,int r,int si,int li,int index){
    if(l > li || r < si)
      return 0;
    if(l <= si && r >= li)
      return tree[index];
   
    int mid = (si + li)/2;
    int left = query(tree,l,r,si,mid,2*index+1);
    int right = query(tree,l,r,mid+1,li,2*index+2);
    return max(left,right);
}

int main()
{   
    vector<int> input{ -5, -5, 2, 2, 2, 2, 3, 7, 7, 7 };
    int n = input.size();
    
    vector<int> arr(n + 1,0); 
  
    // Counting frequencies of all array elements. 
    unordered_map<int, int> cnt; 
    for (int i = 0; i < n; i++) 
        cnt[input[i]]++;  
  
    for (int i = 0; i < n; i++) 
        arr[i] = cnt[input[i]]; 
    
    int x = ceil(log2(n)); 
    int max_size = 2 * (int)pow(2, x) - 1;
    
    vector<int> tree(max_size,0);
    segmentTree(tree,arr,0,n-1,0);
    
    for(int i=0;i<max_size;i++)
      cout<<tree[i]<<" ";
    cout<<endl;
    
    
    int maxOcc; 
    int l = 0 , r = 9;
    
    if (arr[l] == arr[r])   // Case 1: numbers are same at the starting and ending index of the query 
        maxOcc = (r - l + 1); 
    else {       // Case 2: numbers are different 
        int leftmost_same = 0, righmost_same = 0; 
 
        while (l > 0 && arr[l] == arr[l - 1] && l <= r) { 
            l++; 
            leftmost_same++; 
        } 
  
        while (r >= l && r < n - 1 && arr[r] == arr[r + 1]) { 
            r--; 
            righmost_same++; 
        } 
        // Taking maximum of all three 
        maxOcc = max({leftmost_same, righmost_same, query(tree,l,r,0,n-1,0)}); 
    } 
    
    cout<< maxOcc; 
}
