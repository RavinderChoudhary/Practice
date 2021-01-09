#include <bits/stdc++.h>
using namespace std;
int upperBound(vector<int> arr,int k){
    int l = 0;
    int n = arr.size();
    int r = n - 1;
    int res = -1;
    while(l <= r){
        int mid = (l + r)/2;
        if(arr[mid] <= k)
            l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
int lowerBound(vector<int> arr,int k){
    int l = 0;
    int n = arr.size();
    int r = n - 1;
    int res = -1;
    while(l <= r){
        int mid = (l + r)/2;
        if(arr[mid] >= k)
            r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
int countInRange(vector<int> arr,int n,int l,int r){
    return upperBound(arr,r) - lowerBound(arr,l) + 1;
}
int main() {
	vector<int> arr = { 1, 4, 4, 9, 10, 3 }; 
    int n = arr.size(); 
  
    sort(arr.begin(), arr.end()); 
  
    int i = 1, j = 4; 
    cout << countInRange(arr, n, i, j) << endl; 
  
    i = 9, j = 12; 
    cout << countInRange(arr, n, i, j) << endl; 
    return 0; 
}
