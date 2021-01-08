#include <bits/stdc++.h> 
using namespace std; 

const int k = 16; 
const int N = 1e5; 

long long table[N][k + 1]; 

int lcm(int a,int b){
    return (a*b)/__gcd(a,b);
}
void buildSparseTable(vector<int> arr, int n) 
{ 
	for (int j = 0; j < n; j++) 
		table[0][j] = arr[j]; 

	for (int ws = 1; ws <= k; ws++) {
		for (int j = 0; j <= n - (1 << ws); j++) {
		    int window_size = 1 << (ws - 1);
			table[ws][j] = lcm(table[ws-1][j],table[ws - 1][j + window_size]); 
		}
	}
} 

long long query(int L, int R) 
{ 
	long long answer = 1; 
	for (int i = k; i >= 0; i--) { 
		if (L + pow(2,i) - 1 <= R) { 
			answer = lcm(answer,table[i][L]); 
			L += 1 << i;   
		} 
	} 
	return answer; 
} 
 
int main() 
{ 
	vector<int> arr = {5, 7, 5, 2, 10, 12 ,11, 17, 14, 1, 44 }; 
	int n = arr.size(); 

	buildSparseTable(arr, n); 

	cout << query(2, 5) << endl; 
	cout << query(5, 10) << endl; 
	cout << query(0, 10) << endl; 

	return 0; 
} 
