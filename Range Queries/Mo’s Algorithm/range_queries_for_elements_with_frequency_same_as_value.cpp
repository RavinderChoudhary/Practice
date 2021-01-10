#include <bits/stdc++.h> 
using namespace std; 

int block; 
struct Query { 
	int L, R, index; 
}; 

bool compare(Query x, Query y) 
{ 
	// Different blocks, sort by block. 
	if (x.L / block != y.L / block) 
		return x.L / block < y.L / block; 

	// Same block, sort by R value 
	return x.R < y.R; 
} 

void addElement(int x, int& currentAns, unordered_map<int, int>& freq) 
{ 
    if(freq[x] == x)
      currentAns--;
      
	freq[x]++; 

    if(freq[x] == x)
      currentAns++;
} 

void removeElement(int x, int& currentAns,unordered_map<int, int>& freq) 
{ 
    if(freq[x] == x)
      currentAns--;
      
	freq[x]--; 

    if(freq[x] == x)
      currentAns++;
} 


void queryResults(vector<int> a, int n,vector<Query> q, int m) 
{ 
	block = (int)sqrt(n); 
	sort(q.begin(), q.end(), compare);  

	int* ans = new int[m]; 
	
	unordered_map<int, int> freq; 

	int currL = 0, currR = 0; 
	int currentAns = 0; 
 
	for (int i = 0; i < m; i++) { 
	 
		int L = q[i].L, R = q[i].R; 
		int index = q[i].index; 

		while(currL < L) { 
			removeElement(a[currL], currentAns, freq); 
			currL++; 
		} 
		while(currL > L) { 
			currL--; 
			addElement(a[currL], currentAns, freq); 
		} 
		while(currR <= R) { 
			addElement(a[currR], currentAns, freq); 
			currR++; 
		} 
		while(currR > R + 1) { 
			currR--; 
			removeElement(a[currR], currentAns, freq); 
		} 
		ans[index] = currentAns; 
	} 

	for (int i = 0; i < m; i++) 
		cout << "Answer for Query " << (i + 1) << " = " << ans[i] << endl; 
	
} 

int main() 
{ 
	vector<int> a = { 1, 2, 2, 3, 3, 3 }; 
    int n = a.size();

	vector<Query> queries ={    { 0, 1, 0 }, 
            					{ 1, 1, 1 }, 
            					{ 0, 2, 2 }, 
            					{ 1, 3, 3 }, 
            					{ 3, 5, 4 }, 
            					{ 0, 5, 5 } }; 
    int m = queries.size();
	queryResults(a, n, queries,m); 

	return 0; 
} 
