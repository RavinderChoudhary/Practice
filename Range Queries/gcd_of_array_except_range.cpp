// C++ program for queries of GCD excluding 
// given range of elements. 
#include<bits/stdc++.h> 
using namespace std; 


void FillPrefixSuffix(vector<int> &prefix, vector<int> arr, vector<int> &suffix, int n) 
{ 
	prefix[0] = arr[0]; 
	for (int i=1 ;i<n; i++) 
		prefix[i] = __gcd(prefix[i-1], arr[i]); 

	suffix[n-1] = arr[n-1]; 

	for (int i=n-2; i>=0 ;i--) 
		suffix[i] = __gcd(suffix[i+1], arr[i]); 
} 

int GCDoutsideRange(int l, int r, vector<int> prefix, vector<int> suffix, int n) 
{ 
	if(l==0) 
	 return suffix[r+1]; 
	if (r==n-1) 
	 return prefix[l-1]; 
	return __gcd(prefix[l-1], suffix[r+1]); 
} 

int main() 
{ 
	vector<int> arr = {2, 6, 9}; 
	int n = arr.size(); 
	vector<int> prefix(n), suffix(n); 
	FillPrefixSuffix(prefix, arr, suffix, n); 

	int l = 0, r = 0; 
	cout << GCDoutsideRange(l, r, prefix, suffix, n) << endl; 
	l = 1 ; r = 1; 
	cout << GCDoutsideRange(l, r, prefix, suffix, n) << endl; 
	l = 1 ; r = 2; 
	cout << GCDoutsideRange(l, r, prefix, suffix, n) << endl; 
	return 0; 
} 
