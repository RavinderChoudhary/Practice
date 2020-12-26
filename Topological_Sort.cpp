#include <bits/stdc++.h>
using namespace std;

int main() {
    int V = 6;
    vector<int> arr[V];
    vector<int> inDegree(V,0);
    int egdes = 6;
    for(int i=0;i<egdes;i++){
        int a , b;
        cin>>a>>b;
        inDegree[b]++;
        arr[a].push_back(b);
    }
    
    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(inDegree[i] == 0) 
          q.push(i);
    }
    
    while (!q.empty()) {
        int curr = q.top();
        cout<<q.front()<<" ";
        q.pop();
        
        vector<int> temp = arr[curr];
        for (auto num : temp) {
            inDegree[num]--;
            if (inDegree[num] == 0) {
                q.push(num);
            }
        }
    }
    
	return 0;
}


