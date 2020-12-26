#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[],int u,int v){
	adj[u].push_back(v);
}
void dfs(vector<int> adj[],vector<bool>& visited,int u){	 
     
     if(visited[u] == true)
       return;
     visited[u] = true;
     cout<<u<<" ";
     
	 for(int v=0;v<adj[u].size();v++){
	 	dfs(adj,visited,adj[u][v]);    
	 }  
}
int main(){
    int V = 5;
	vector<int> adj[V];
	addEdge(adj,0,2);
	addEdge(adj,0,3);
	addEdge(adj,1,0);
	addEdge(adj,2,1);
	addEdge(adj,3,4);
	vector<bool> visited(V);
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++)
		  visited[j]=false;
		
		cout<<"start vectex "<<i<<" : ";
		dfs(adj,visited,i);
		cout<<endl;
	}
    for(int i=0;i<V;i++)
	   adj[i].clear();
}
