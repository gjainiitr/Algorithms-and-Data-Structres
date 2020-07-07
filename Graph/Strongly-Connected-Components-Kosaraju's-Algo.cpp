/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
*/
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


void DFS(vector<int> adj[], int V, bool visited[], int j, stack<int> &s) {
    visited[j] = true;
    for(int i=0; i<adj[j].size(); i++) {
        if(!visited[adj[j][i]]) {
            DFS(adj,V,visited,adj[j][i],s);
        }
    }
    s.push(j);
}
void DFSUtil(vector<int> *adj, int V, bool visited[], int j) {
    visited[j] = true;
    for(int i=0; i<adj[j].size(); i++) {
        if(!visited[adj[j][i]]) {
            DFSUtil(adj,V,visited,adj[j][i]);
        }
    }
}
vector<int> * reverseGraph(vector<int> adj[], int V) {
    vector<int>* res;
    res = new vector<int>[V];
    for(int i=0; i<V; i++) {
        for(int j=0; j<adj[i].size(); j++) {
            res[adj[i][j]].push_back(i);
        }
    }
    return res;
    
}
int kosaraju(int V, vector<int> adj[])
{
    // Your code here
    bool visited[V] = {0};
    stack<int> s;
    for(int i=0; i<V; i++) {
        if(!visited[i]) DFS(adj,V,visited,i,s);    
    }
    int res=0;
    
    // cout<<endl;
    // while(!s.empty()) {
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    // cout<<endl;
    
    for(int i=0; i<V; i++) visited[i]=0;
    vector<int> *reversedGraph = reverseGraph(adj,V); // is it really reversed??
    
    // for(int i=0; i<V; i++) {
    //     cout<<i<<" : ";
    //     for(int j=0; j<adj[i].size(); j++) {
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // for(int i=0; i<V; i++) {
    //     cout<<i<<" : ";
    //     for(int j=0; j<reversedGraph[i].size(); j++) {
    //         cout<<reversedGraph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    while(s.size()>0) {
        int temp = s.top();
        s.pop();
        if(!visited[temp]) {
            DFSUtil(reversedGraph, V, visited, temp);
            res++; 
        }
    }
    return res;
}

// { Driver Code Starts.

int main()
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int a,b ;
   	    cin>>a>>b;
   	    int m,n;
   	    vector<int> adj[a+1];
        for(int i=0;i<b;i++){
            cin>>m>>n;
            adj[m].push_back(n);
        }
        // exit(0);
        cout<<kosaraju(a, adj)<<endl;
    }
    return 0;
}  // } Driver Code Ends
