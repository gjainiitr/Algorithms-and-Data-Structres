/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


bool isSafe(bool graph[101][101], int V, int j, int i, int color[]) {
    for(int p=0; p<V; p++) {
        if(graph[i][p]==1) {
            if(color[p]==j) return false;
        }
    }
    return true;
}
bool check(bool graph[101][101], int m, int V, int color[]) {
    int i;
    for(i=0; i<V; i++) {
        if(color[i]==-1) break;
    } 
    if(i==V) return true;
    for(int j=0; j<m; j++) {
        if(isSafe(graph,V,j,i,color)) { // to assign color j to ith vertex
            color[i] = j;
            if(check(graph,m,V,color)==true) return true;
            color[i] = -1;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V) {
    int color[V];
    for(int i=0; i<V; i++) color[i]=-1;
    if(check(graph,m,V,color)==true) return true;
    else return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
