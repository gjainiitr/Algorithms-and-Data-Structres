/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/possible-paths-between-2-vertices-1587115620/1
*/
#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int> *adj;

  public:
    Graph(int V);
    void addEdge(int u, int v);
    int countPaths(int s, int d);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V + 1];
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}


 // } Driver Code Ends


// The Graph structure is as folows
/*
class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int u, int v);
    int countPaths(int s, int d);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V+1];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}
*/
int paths(list<int> *adj, bool recStack[], int s, int d) {
    if(s==d) return 1;
    int res = 0;
// 	for(int i=0; i<adj[s].size(); i++) {
// 		int curr = adj[s][i];
// 		if(recStack[curr]==0) {
// 			recStack[curr] = 1;
// 				res += paths(adj,recStack,curr,d);
// 			recStack[curr] = 0;
// 		}
// 	}
	list<int> :: iterator curr;
    for( curr=adj[s].begin(); curr!=adj[s].end(); curr++) {
        // int curr = *it;
        int x = *curr;
        if(recStack[x]==0) {
            recStack[x]=1;
            res += paths(adj,recStack,x,d);
            
            recStack[x]=0;
        }
    }
	return res;
}
// Function to find paths between 2 nodes
int Graph::countPaths(int s, int d) {
    // Your code here
    int res=0;
    bool recStack[V] = {0};
    // for(int i=0; i<adj[s].size(); i++) {
        
    // }
    recStack[s]=1;
    return paths(adj, recStack, s, d);
    
    // return res;
}

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        int u, v;
        Graph g(N);
        while (M--) {
            cin >> u >> v;
            g.addEdge(u, v);
        }
        int s, e;
        cin >> s >> e;
        cout << g.countPaths(s, e) << endl;
    }
    return 0;
}  // } Driver Code Ends
