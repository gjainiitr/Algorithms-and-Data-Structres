/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/

#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/
bool dfsRec(vector<int> adj[], int s,bool visited[], int parent) {
    visited[s]=true;
    for(int x:adj[s]) {
        if(visited[x]==false) {
            if(dfsRec(adj,x,visited,s)==true) return true;
        } else if(parent!=x) return true;
    }
    return false;
}
bool isCyclic(vector<int> adj[], int V)
{
   // Your code here
   bool visited[V];
   for(int i=0; i<V; i++) visited[i]=false;
   
   for(int i=0; i<V; i++) {
       if(visited[i]==false) {
           if(dfsRec(adj,i,visited,-1)==true)   return true;
       }
   }
   return false;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends
