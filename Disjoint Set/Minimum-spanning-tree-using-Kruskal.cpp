/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/minimum-spanning-tree3233/1
*/
//Initial Template for C++


#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


//User function Template for C++


/**
 *  ith value in adj vector contains information between the node connected to it and weight between them.
 *  Example. for a value 2 3 1, Node 2 and Node 3 has weight 1. adj[2] = {3,1} and adj[3] = {2,1}.
 *  n -> number of nodes
 *  m -> total number of edges
 *  return the mst value
*/
struct Edge {
    int src,dst;
    long long int weight;
    Edge(int s, int d, long long int w) {
        src = s;
        dst = d;
        weight = w;
    }
};
int find(int x, int parent[]) {
    if(parent[x]==x) return x;
    parent[x] = find(parent[x], parent);
    return parent[x];
}
void unionSet(int x, int y, int rank[], int parent[]) {
    int x_rep = find(x,parent);
    int y_rep = find(y,parent);
    if(x_rep!=y_rep) {
        if(rank[x_rep]>rank[y_rep]) {
            parent[y_rep] = x_rep;
            rank[y_rep] += 1;
        } else {
            parent[x_rep] = y_rep;
            rank[x_rep] += 1;
        }
    }
    return;
}
bool myCmp(Edge a, Edge b) {
    
    return (a.weight < b.weight);
}
long long int kruskalDSU(vector<pair<int, long long int>> adj[], int n, int m) { // adj is an array of size n. Each member of which is a vector. Each vector contains a pair
    int parent[n+1],rank[n+1];
    for(int i=0; i<=n; i++) {
        parent[i]=i;
        rank[i]=0;
    }
    vector<Edge> edges;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<adj[i].size(); j++) {
            if(i>adj[i][j].first) continue;
            edges.push_back(Edge(i,adj[i][j].first,adj[i][j].second));
        }
    }
    sort(edges.begin(), edges.end(), myCmp);
    // now the array is sorted;
    long long res=0;
    int count=0;
    int src,dst;
    for(int i=0; i<m; i++) {
        if(count == n-1) break;
        // if(i > (adj[i]).first) continue;
        src = find(edges[i].src,parent);
        dst = find(edges[i].dst, parent);
        if(src!=dst) {
            res += edges[i].weight;
            unionSet(src,dst,rank,parent);
        }
    }
    return res;
}

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;

    vector<pair<int, long long int>> adj[100009];

    while(t--) {

        int n,m;
        cin>>n>>m;

        int u,v;
        long long w;
        for(int i=0; i<m; i++) {
            cin>>u>>v>>w;
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }

        cout<<kruskalDSU(adj, n, m)<<endl;

        for(int i=0; i<=n; i++) {
            adj[i].clear();
        }
    }
    return 0;
}
  // } Driver Code Ends
