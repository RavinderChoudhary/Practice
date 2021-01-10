// https://www.geeksforgeeks.org/array-range-queries-for-searching-an-element/

#include <bits/stdc++.h> 
using namespace std; 

int block; 
struct Query 
{ 
	int L, R, X; 
}; 

bool compare(Query x, Query y) 
{ 
	// Different blocks, sort by block. 
	if (x.L / block != y.L / block) 
		return x.L / block < y.L / block; 

	// Same block, sort by R value 
	return x.R < y.R; 
} 

void queryResults(vector<int> a, int n,vector<Query> q, int m) 
{ 
	block = (int)sqrt(n); 
	sort(q.begin(), q.end(), compare); 
	int currL = 0, currR = 0; 

	// To store the frequencies of elements of the given range 
	map<int, int> mp; 

	for (int i = 0; i < m; i++) { 

		int L = q[i].L, R = q[i].R, X = q[i].X; 

		while (currL < L)       //  shift current left to right side
		{ 
			mp[a[currL]]--; 
			currL++; 
		} 
		while (currL > L)      //  shift current left to left side
		{ 
			mp[a[currL - 1]]++; 
			currL--; 
		} 
		while (currR <= R)     //  shift current right to right side
		{ 
			mp[a[currR]]++; 
			currR++; 
		} 
		while (currR > R + 1)   //  shift current right to left side
		{ 
			mp[a[currR - 1]]--; 
			currR--; 
		} 

		// Print if X exists or not 
		if (mp[X] != 0) 
			cout << X << " exists between [" << L << ", " << R << "] " << endl; 
		else
			cout << X << " does not exist between ["<< L << ", " << R << "] " << endl; 
	} 
} 
 
int main() 
{ 
	vector<int> a = { 1, 1, 5, 4, 5 }; 
	int n = a.size(); 
	vector<Query>  q = { 
	                               { 0, 2, 2 }, 
	                               { 1, 4, 1 }, 
	                               { 2, 4, 5 } 
	                          }; 
	int m = q.size(); 
	queryResults(a, n, q, m); 
	return 0; 
} 
