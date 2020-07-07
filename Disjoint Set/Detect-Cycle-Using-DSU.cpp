/*
 Problem URL :- https://practice.geeksforgeeks.org/problems/detect-cycle-using-dsu/1
*/

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

// User function Template for C++

/*  Function to check if there is cycle in graph
*   adj[]: array of vectors to represent graph
*   n and e are number of nodes and edges respectively
*   parent[]: array to store parent of nodes. Each index stores its node value
* initially
*   rank1[]: Each node from 1 to n store initial size as 1.
*/
int find(int x, int par[]) {
    if(x==par[x]) return x;
    else {
        par[x] = find(par[x], par);
        return par[x];
    }
}
bool makeunion(int a, int b, int par[], int rank1[]) {
    int a_rep = find(a,par);
    int b_rep = find(b,par);
    // if(a_rep && b_rep!=b &&)
    if(a_rep==b_rep) return true;
    else {
        if(rank1[a_rep]>rank1[b_rep]) {
            par[b_rep] = a_rep;
            rank1[b_rep] += 1;
        } else {
            par[a_rep] = b_rep;
            rank1[a_rep] += 1;
        }
        return false;
    }
}
bool findCycle(vector<int> adj[], int parent[], int rank[], int n, int e) {

    // your code here
    for(int i=1; i<=n; i++) {
        int size = adj[i].size();
        for(int j=0; j<size; j++) {
            if(i>adj[i][j]) continue;
            if(makeunion(i,adj[i][j],parent,rank)==true) return true;
        }
    }
    return false;
}


// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, e;
        cin >> n >> e;
        vector<int> adj[n + 1];

        int parent[n + 1];

        int rank1[n + 1];

        for (int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // makeSet operation
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank1[i] = 1;
        }

        if (findCycle(adj, parent, rank1, n, e)) {
            cout << "1";
        } else
            cout << "0";

        cout << endl;
    }

    return 0;
}
  // } Driver Code Ends
