# https://www.youtube.com/watch?v=2EpX9LkO2T0

#include <bits/stdc++.h> 
using namespace std; 
#define MAX 500 

int lookup[MAX][MAX]; 
 
void buildSparseTable(vector<int> arr, int n) 
{  
	for (int i = 0; i < n; i++) 
		lookup[i][0] = arr[i]; 

	for (int j = 1; j <= n; j++) {
		for (int i = 0; i <= n - (1 << j); i++){ 
		    int window_size = 1 << (j - 1);
			lookup[i][j] = __gcd(lookup[i][j - 1], lookup[i + window_size][j - 1]);
		}
	}
} 
 
int query(int L, int R) 
{ 
	int j = (int)log2(R - L + 1); 

	return __gcd(lookup[L][j], lookup[R - (1 << j) + 1][j]); 
} 

int main() 
{ 
	vector<int> a = { 7, 2, 3, 0, 5, 10, 3, 12, 18 }; 
	int n = a.size(); 
	buildSparseTable(a, n); 
	cout << query(0, 2) << endl; 
	cout << query(1, 3) << endl; 
	cout << query(4, 5) << endl; 
	return 0; 
} 
