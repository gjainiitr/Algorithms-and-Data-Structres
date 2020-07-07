/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/topological-sort/1
*/
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*   NOTE: You must return dynamically allocated array
*/
void findIndegree(vector<int> adj[], int V, int indegree[]) {
     for(int i=0; i<V; i++) {
         for(int x:adj[i]) {
             indegree[x]++;
         }
     }   
}
int* topoSort(int V, vector<int> adj[]) {
    // Your code here
    int indegree[V];
    for(int i=0; i<V; i++) indegree[i]=0;
    findIndegree(adj,V,indegree);
    
    queue<int> q;
    for(int i=0; i<V; i++) {
        if(indegree[i]==0) q.push(i);
    }
    
    int *arr;
    arr = new int[V];
    int pointer=0;
    
    while(q.size()>0) {
        int temp = q.front();
        q.pop();
        arr[pointer]=temp;
        pointer++;
        
        for(int x:adj[temp]) {
            indegree[x]-=1;
            if(indegree[x]==0) q.push(x);
        }
    }
    return arr;
}


// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, int* res, vector<int> adj[]) {
    bool flag = true;
    for (int i = 0; i < V && flag; i++) {
        int n = adj[res[i]].size();
        for (auto j : adj[res[i]]) {
            for (int k = i + 1; k < V; k++) {
                if (res[k] == j) n--;
            }
        }
        if (n != 0) flag = false;
    }
    if (flag == false) return 0;
    return 1;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        int* res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}
  // } Driver Code Ends
