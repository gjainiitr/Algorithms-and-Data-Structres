/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/mother-vertex/1
*/
//Initial Template for C++


#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends


/*
 * Function to find if there is a mother vertex in the given graph 
 * V: number of vertices in the graph
 * adj[]: graph representation
 */

void dfs(int src,vector<bool> &vis,vector<int> adj[]){
    vis[src]=true;
    for(int i=0;i<adj[src].size();i++){
        if(vis[adj[src][i]]==false)
            dfs(adj[src][i],vis,adj);
    }
}

int findMother(int n, vector<int> adj[]) 
{ 
    int mother=0;
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        if(vis[i]==false)
            {
            dfs(i,vis,adj);
            mother=i;
            }

    }

    vector<bool> visited(n,false);
        dfs(mother,visited,adj);
        for(int i=0;i<n;i++){
            if(visited[i]==false)
                mother=-1;
        }
    return mother;
} 

// { Driver Code Starts.

int main() 
{ 
    int T;
    cin>>T;
    while(T--){
        int num, edges;
        cin>>num>>edges;
        
        vector<int> adj[num];
        
        int u, v;
        while(edges--){
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        cout<<findMother(num, adj)<<endl;
    }

	return 0;
}   // } Driver Code Ends
