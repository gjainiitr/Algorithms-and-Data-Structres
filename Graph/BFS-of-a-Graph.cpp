/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
*/

//{
	#include<bits/stdc++.h>
	using namespace std;
 // } Driver Code Ends
/* You have to complete this function*/

/* Function to do BFS of graph
*  adj[]: array of vectors i.e. Graph
*  vis[]: array to keep track of visited nodes
*/
void bfs(int s, vector<int> adj[], bool vis[], int N)
{
    // Your code here
    if(N==0) return;
    queue<int> q;
    q.push(s);
    vis[s]=true;
    
    while(q.size()>0) {
        int temp = q.front();
        q.pop();
        cout<<temp<<" ";
        for(int x:adj[temp]) {
            if(vis[x]==false) {
                vis[x]=true;
                q.push(x);
            }
        }
    }
    
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        
        int N, E;
        cin>>N>>E;
        vector<int> adj[N];
        bool vis[N] = {false};
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        bfs(0, adj, vis, N);

        cout<<endl;

    }
}

  // } Driver Code Ends
