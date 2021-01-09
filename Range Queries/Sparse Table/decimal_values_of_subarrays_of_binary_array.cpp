#include <bits/stdc++.h> 
using namespace std; 

const int k = 16; 
const int N = 1e5; 

long long table[N][k + 1]; 

void buildSparseTable(vector<int> arr, int n) 
{ 
	for (int j = 0; j < n; j++) 
		table[0][j] = arr[j]; 

	for (int ws = 1; ws <= k; ws++) {
		for (int j = 0; j <= n - (1 << ws); j++) {
		    int window_size = 1 << (ws - 1);
		    int shift = pow(2,ws-1);
			table[ws][j] = (table[ws-1][j]<<shift) | table[ws - 1][j + window_size]; 
		}
	}
} 

long long query(int L, int R) 
{ 
	long long answer = 0; 
	for (int i = k; i >= 0; i--) { 
		if (L + pow(2,i) - 1 <= R) { 
		    answer <<= (i+1);
			answer = answer | table[i][L]; 
			L += 1 << i;   
		} 
	} 
	return answer; 
} 
 
int main() 
{ 
	vector<int> arr = {1,0,1,1,1,0,1,0,1,1}; 
	int n = arr.size(); 

	buildSparseTable(arr, n); 
    cout << query(0, 2) << endl;   // 5
 	cout << query(2, 8) << endl;   // 117
 	cout << query(4, 9) << endl;   // 43
 	cout << query(1, 9) << endl;   // 235
 	cout << query(0, 9) << endl;   // 747

	return 0; 
}
