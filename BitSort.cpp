#include <bits/stdc++.h>
using namespace std;

void sortArr(vector<int> arr,int digit,int si,int li){
     if(si > li)
       return;
     if(digit == 0){
         cout<<arr[si]<<" ";
         return;
     }
     
     int j = si;
     for(int i=si;i<=li;i++){
        int val = arr[i] >> (digit-1);
        if(!(val & 1)) 
          swap(arr[j++],arr[i]);
     }
     
     sortArr(arr,digit-1,si,j-1);
     sortArr(arr,digit-1,j,li);
}
int main() {
	vector<int> arr = {12,14,18,6,3,1,7,9,13,10,8};
	int n = arr.size();
	int mx = *max_element(arr.begin(),arr.end());
	int digit = log2(mx) + 1;
	
	sortArr(arr,digit,0,n-1);
	return 0;
}
