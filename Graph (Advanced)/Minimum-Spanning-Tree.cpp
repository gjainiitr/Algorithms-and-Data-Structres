/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V,int E,vector<vector<int> > graph);
// Driver code

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int V,E;
        cin>>V>>E;
        vector< vector<int> > graph(V,vector<int>(V,INT_MAX));

        while(E--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout<<spanningTree(V,E,graph)<<endl;
    }
    return 0;
}

// } Driver Code Ends


int findMin(bool visited[], int keyValue[], int V) {
    int res = -1, minValue = INT_MAX;
    for(int i=0; i<V; i++) {
        if(!visited[i]) {
            if(keyValue[i] < minValue) {
                minValue = keyValue[i];
                res = i;
            }
        }
    }
    return res;
}

int spanningTree(int V,int E,vector<vector<int> > graph)
{
    bool visited[V] = {0};
    int keyValue[V];
    for(int i=0; i<V; i++) keyValue[i]=INT_MAX;
    keyValue[0]=0;
    int minVertex=0;
    // int count=0;
    while(true) {
        minVertex = findMin(visited,keyValue,V);
        if(minVertex==-1) break;
        visited[minVertex] = 1;
        for(int i=0; i<V; i++) {
            if(!visited[i] && graph[minVertex][i]<keyValue[i]) {
                keyValue[i]=graph[minVertex][i];
            }
        }
        // count++;
    }
    int res=0;
    for(int i=0; i<V; i++) res += keyValue[i];
    return res;
}
