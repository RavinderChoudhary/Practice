

#include <bits/stdc++.h>
using namespace std;
int TravellingSalesmanProblem(vector<vector<int>> paths,int src,int dest,vector<bool> visited){
     
     visited[src] = true;
     int mini = INT_MAX;
     for(int i=0;i<paths.size();i++){
         if(visited[i] == false){
             mini = min(mini,paths[src][i] + TravellingSalesmanProblem(paths,i,dest,visited));
         }
     }
     
     if(mini == INT_MAX)
       return paths[src][dest];
     return mini; 
}
int main() {
    int vertex = 4;
	vector<vector<int>> paths{
	  { 0, 10, 15, 20 }, 
        { 10, 0, 35, 25 }, 
        { 15, 35, 0, 30 }, 
        { 20, 25, 30, 0 }
	};
	
	int src = 0;
	int dest = src;
	vector<bool> visited(vertex,false);
	cout<<TravellingSalesmanProblem(paths,src,dest,visited);
	return 0;
}
