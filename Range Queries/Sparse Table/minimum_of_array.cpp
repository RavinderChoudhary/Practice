#include <bits/stdc++.h> 
using namespace std; 
#define MAX 500 

int lookup[MAX][MAX]; 

void buildSparseTable(vector<int> arr, int n) 
{ 
	for(int i = 0; i < n; i++) 
		lookup[i][0] = arr[i]; 

	for(int j = 1; (1 << j) <= n; j++) {            

		for(int i = 0; (i + (1 << j) - 1) < n; i++) {     //  size = i + 2^j
            int window_size = 1 << (j - 1);
			if(lookup[i][j - 1] < lookup[i + window_size][j - 1])   lookup[i][j] = lookup[i][j - 1]; 
			else  lookup[i][j] = lookup[i + window_size][j - 1]; 
		} 
	} 
} 

int query(int L, int R) 
{ 
	int j = (int)log2(R - L + 1); 

	if(lookup[L][j] <= lookup[R - (1 << j) + 1][j])   return lookup[L][j]; 
	else  return lookup[R - (1 << j) + 1][j]; 
} 

int main() 
{ 
	vector<int> a = { 7, 2, 3, 0, 5, 10, 3, 12, 18 }; 
	int n = a.size(); 
	buildSparseTable(a, n); 
	cout << query(0, 4) << endl; 
	cout << query(4, 7) << endl; 
	cout << query(7, 8) << endl; 
	return 0; 
} 
