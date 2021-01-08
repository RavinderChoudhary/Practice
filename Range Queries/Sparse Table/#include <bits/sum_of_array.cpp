#include <bits/stdc++.h> 
using namespace std; 

const int k = 16; 
const int N = 1e5; 

long long table[N][k + 1]; 

void buildSparseTable(vector<int> arr, int n) 
{ 
	for (int i = 0; i < n; i++) 
		table[i][0] = arr[i]; 

	for (int j = 1; j <= k; j++) {
		for (int i = 0; i <= n - (1 << j); i++) {
		    int window_size = 1 << (j - 1);
			table[i][j] = table[i][j - 1] + table[i + window_size][j - 1]; 
		}
	}
} 

long long query(int L, int R) 
{ 
	long long answer = 0; 
	for (int j = k; j >= 0; j--) { 
		if (L + pow(2,j) - 1 <= R) { 
			answer = answer + table[L][j]; 
			L += 1 << j;   
		} 
	} 
	return answer; 
} 
 
int main() 
{ 
	vector<int> arr = { 3, 7, 2, 5, 8, 9 }; 
	int n = arr.size(); 

	buildSparseTable(arr, n); 

	cout << query(0, 5) << endl; 
	cout << query(3, 5) << endl; 
	cout << query(2, 4) << endl; 

	return 0; 
} 
