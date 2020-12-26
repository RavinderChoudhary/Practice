#include <bits/stdc++.h>
using namespace std;
void addEdge(vector <pair<int, int> > adj[], int u, int v, int wt) 
{ 
    adj[u].push_back(make_pair(v, wt)); 
    adj[v].push_back(make_pair(u, wt)); 
} 
void printGraph(vector<pair<int,int> > adj[], int V) {
    for(int u=0;u<V;u++)
    {   cout<< u << "  ->  ";
        for(auto it = adj[u].begin(); it!=adj[u].end(); it++) 
          cout << "(" << it->first << "," << it->second << ")  "; 
        cout<<endl;
    }
}
int main() {
  
    // weighted graph 
    int V = 5; 
    vector<pair<int, int> > adj[V]; 
    addEdge(adj, 0, 1, 10); 
    addEdge(adj, 3, 2, 5); 
    printGraph(adj , V);
}
