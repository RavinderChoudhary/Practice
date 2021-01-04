#include<bits/stdc++.h>
using namespace std; 

// Time Complexity : O(1) 
void update(vector<int> &input,vector<int> &block, int idx, int val) 
{ 
    int blk_sz = block.size(); 
	int blockNumber = idx / blk_sz; 
	block[blockNumber] += val - input[idx]; 
	input[idx] = val; 
} 

// Time Complexity : O(sqrt(n)) 
int query(vector<int> &input,vector<int> &block, int l, int r) 
{ 
	int sum = 0; 
	int blk_sz = block.size(); 
	while (l<r && l%blk_sz!=0 && l!=0) 
	{ 
		// traversing first block in range 
		sum += input[l]; 
		l++; 
	} 
	while (l+blk_sz <= r) 
	{ 
		// traversing completely overlapped blocks in range 
		sum += block[l/blk_sz]; 
		l += blk_sz; 
	} 
	while (l<=r) 
	{ 
		// traversing last block in range 
		sum += input[l]; 
		l++; 
	} 
	return sum; 
} 

void preprocess(vector<int> &input,vector<int> &block, int n) 
{ 
	int blk_idx = -1; 
	int blk_sz = sqrt(n); 
    
	// building the decomposed array 
	for (int i=0; i<n; i++) 
	{ 
		if (i%blk_sz == 0) 
			blk_idx++; 
	 
		block[blk_idx] += input[i]; 
	} 
} 
 
int main() 
{ 
	vector<int> input = {1, 5, 2, 4, 6, 1, 3, 5, 7, 10}; 
	int n = input.size(); 
    vector<int> block(sqrt(n),0);
	preprocess(input,block, n); 

	cout << "query(3,8) : " << query(input,block, 3, 8) << endl; 
	cout << "query(1,6) : " << query(input,block, 1, 6) << endl; 
	update(input,block,8, 0); 
	cout << "query(8,8) : " << query(input,block, 8, 8) << endl; 
	return 0; 
} 
