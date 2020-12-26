/**
 *  insert
 *  insertWeightedGraph
 *  display
 *  displayWeightedGraph
 *  dfs
 *  bfs
 *  hasPath
 *  minDist
 *  PrimsAlgo
 *  DijkstraAlgo
 *  Kruskal
 *  BellmanFordAlgo
* */

#include <bits/stdc++.h>
using namespace std;
struct Edge
{
  int src;
  int dest;
  int wt;
};
void insert(vector<int> arr[],int a,int b){
    arr[a].push_back(b);
    arr[b].push_back(a);
}
void insertWeightedGraph(vector<pair<int,int> > wtArr[],int a,int b,int wt){
    wtArr[a].push_back({b,wt});
    wtArr[b].push_back({a,wt});
}
void display(vector<int> arr[],int V){
    for(int i=0;i<V;i++){
        cout<<i<<" : ";
        for(int j=0;j<arr[i].size();j++)
          cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}
void displayWeightedGraph(vector<pair<int,int> > wtArr[],int V){
    for(int i=0;i<V;i++){
        cout<<i<<" : ";
        for(int j=0;j<wtArr[i].size();j++)
          cout<<"("<<wtArr[i][j].first<<","<<wtArr[i][j].second<<")";
        cout<<endl;
    }
}
void dfs(vector<int> arr[],vector<bool> &visited1,int src,int V){
    visited1[src] = true;
    cout<<src<<" ";
    
    for(int i=0;i<arr[src].size();i++){
        if(visited1[arr[src][i]] == false)
            dfs(arr,visited1,arr[src][i],V);
    }
}
void bfs(vector<int> arr[],vector<bool> &visited2,int src,int V){
    queue<int> q;
    q.push(src);
    visited2[src] = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        cout<<u<<" ";
        
        for(int i=0;i<arr[u].size();i++)
           if(visited2[arr[u][i]] == false){
            q.push(arr[u][i]);
            visited2[arr[u][i]] = true;
           }
    }
}
bool hasPath(vector<int> arr[],vector<bool> &visited3,int src,int dest,int V,vector<int> &res){
    res.push_back(src);
    if(src == dest)
      return true;
    
    visited3[src] = true;

    for(int i=0;i<arr[src].size();i++){
        if(visited3[arr[src][i]] == false){
            if(hasPath(arr,visited3,arr[src][i],dest,V,res) == true)
               return true;
        }
    }
    res.pop_back();
    return false;
}
int minDist(vector<bool> visited,vector<int> dist){
     int minIndex;
     int minVal = INT_MAX;
     for(int i=0;i<dist.size();i++){
         if(visited[i] == false && dist[i] < minVal){
             minVal = dist[i];
             minIndex = i;
         }
     }
     return minIndex;
}
void PrimsAlgo(vector<pair<int,int> > wtArr[],int src,int V){
     vector<int> dist(V,INT_MAX);
     dist[src] = 0;
     int counter =  0;
     vector<bool> visited(V,false);
     vector<int> parent(V,-1);
    
     while(counter < V - 1){
         int u = minDist(visited,dist);
         visited[u] = true;
         for(int i=0;i<wtArr[u].size();i++){
             int v = wtArr[u][i].first;
             if(visited[v] == false && dist[v] > wtArr[u][i].second){
                 dist[v] = wtArr[u][i].second;
                 parent[v] = u;
             }
         }
         counter++;
     }
   

     for (int i = 1; i < V; i++) 
      for(int j=0;j<wtArr[i].size();j++)
         if(wtArr[i][j].first == parent[i])
           cout<<parent[i]<<" - "<<i<<" \t"<<wtArr[i][j].second<<" \n"; 
    
     cout<<endl;
}
void DijkstraAlgo(vector<pair<int,int> > wtArr[],int src,int V){
     vector<int> dist(V,INT_MAX);
     dist[src] = 0;
     int counter =  0;
     vector<bool> visited(V,false);
     vector<int> parent(V,-1);
    
     while(counter < V - 1){
         int u = minDist(visited,dist);
         visited[u] = true;
         for(int i=0;i<wtArr[u].size();i++){
             int v = wtArr[u][i].first;
             if(visited[v] == false && (dist[v] > wtArr[u][i].second + dist[u])){
                 dist[v] = wtArr[u][i].second + dist[u];
                 parent[v] = u;
             }
         }
         counter++;
     }
     for(int i=0;i<V;i++)
       cout<<dist[i]<<" ";
     cout<<endl;
}
int getParent(vector<int> parent,int x){
    if(parent[x] == x)
      return x;
    else return getParent(parent,parent[x]);
}
void Kruskal(Edge edges[],int E,int V){
    Edge output[V-1];
    
    vector<int> parent(V,0);
    for(int i=0;i<V;i++)
      parent[i] = i;
      
    sort(edges,edges+E,[] (Edge e1,Edge e2) -> bool { return e1.wt < e2.wt; });
    
    int i = 0;
    int count = 0;
    while(count < V - 1 && i < E){
        int srcParent = getParent(parent,edges[i].src);
        int destParent = getParent(parent,edges[i].dest);
        
        if(srcParent != destParent){
            parent[srcParent] = destParent;
            output[count++] = edges[i];
        }
        i++;
    }
    
    for(int i=0;i<V-1;i++)
      cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].wt<<endl;
}
void BellmanFordAlgo(vector<pair<int,int> > wtArr[],int V){
    vector<int> dist(V,INT_MAX);
	dist[0] = 0;
	
	for(int count=0;count<V-1;count++){
	    for(int u=0;u<V;u++){
	        for(int index=0;index<wtArr[u].size();index++){
	            int src = u;
	            int dest = wtArr[u][index].first;
	            int wt = wtArr[u][index].second;
	            if(dist[src] != INT_MAX)
	              dist[dest] = min(dist[dest] , dist[src] + wt);
	        }
	    }
	}
	
	
	
    for(int u=0;u<V;u++){
        for(int index=0;index<wtArr[u].size();index++){
            int src = u;
            int dest = wtArr[u][index].first;
            int wt = wtArr[u][index].second;
            if(dist[src] != INT_MAX && dist[src] + wt < dist[dest]){
              cout << "Negative Weight Cycle Found!!";
			  return;  
            }
        }
    }
	
	
	for(int i=0;i<V;i++)
	  cout<<dist[i]<<" ";
}
int main()
{   
    int V = 8;
    vector<int> arr[V];
    int egdes = 9;
    for(int i=0;i<egdes;i++){
        int a , b;
        cin>>a>>b;
        insert(arr,a,b);
    }
    display(arr,V);
    vector<bool> visited1(V,false);
    int src = 0;
    cout<<"DFS : ";
    dfs(arr,visited1,src,V);
    cout<<endl;
    cout<<"BFS : ";
    vector<bool> visited2(V,false);
    bfs(arr,visited2,src,V);
    vector<bool> visited3(V,false);
    cout<<endl;
    src = 0;
    int dest = 6;
    vector<int> res;
    cout<<hasPath(arr,visited3,src,dest,V,res)<<endl;
    for(auto it : res)
      cout<<it<<" ";
    
    V = 5;
    vector<pair<int,int>> wtArr[V];
    int E = 7;
    Edge edges[E];
    for(int i=0;i<E;i++){
      int a , b , wt;
      cin>>a>>b>>wt;
      edges[i].src = a; edges[i].dest = b ; edges[i].wt = wt; 
      insertWeightedGraph(wtArr,a,b,wt);
    }
    displayWeightedGraph(wtArr,V);
    PrimsAlgo(wtArr,0,V);
    DijkstraAlgo(wtArr,0,V);
    Kruskal(edges,E,V);
}
