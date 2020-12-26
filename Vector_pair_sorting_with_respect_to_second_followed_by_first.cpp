#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2){
    if(p1.first == p2.first)
       return p1.second < p2.second;
    return p1.first < p2.first;
}  

int main() {
	vector<pair<int,int>> arr;
	arr.push_back({4,3});
	arr.push_back({7,3});
	arr.push_back({5,5});
	arr.push_back({5,4});
	sort(arr.begin(),arr.end(),compare);
	for(auto i : arr){
	    cout<<i.first <<" "<<i.second<<endl;
	}
	return 0;
}
