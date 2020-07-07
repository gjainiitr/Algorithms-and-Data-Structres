/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
*/
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool dfsRec(vector<int> adj[], bool recStack[], bool visited[], int s) {
    visited[s]=true;
    recStack[s]=true;
    for(int x:adj[s]) {
        if(visited[x]==false) {
            if(dfsRec(adj,recStack,visited,x)==true) return true;
        } else {
            if(recStack[x]==true) return true;
        }
    }
    
    recStack[s]=false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    bool visited[V], recStack[V];
    for(int i=0; i<V; i++) {
        visited[i]=false;
        recStack[i]=false;
    }
    for(int i=0; i<V; i++) {
        if(visited[i]==false) {
            if(dfsRec(adj,recStack,visited,i)==true) return true;
        }
    }
    return false;
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
