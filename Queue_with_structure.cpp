#include <bits/stdc++.h>
using namespace std;

struct queueEntry 
{ 
    int v;     // Vertex number 
    int dist;  // Distance of this vertex from source 
}; 
int main() {
  
    queue<queueEntry> q;  
    queueEntry obj1;
    obj1.v=0;
    obj1.dist=0;
    q.push(obj1);
     
    while(!q.empty()){
        cout<<q.front().v << " "<< q.front().dist<<endl;
        q.pop();
    }
}
