/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1
*/

// { Driver Code Starts
//Initial template
#include<bits/stdc++.h>
using namespace std;
class Graph
{
	int V;
	list<int> *adj;
public:
	Graph(int V); 
	int addEdge(int v, int w);
	bool isBridge(int u, int v);
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
int Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// Driver Program
int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        int s,N;
        cin>>s>>N;
        Graph *g = new Graph(s);
        for(int i=0;i<N;i++)
        {
            int u,v;
            cin>>u>>v;
            g->addEdge(u,v);
        }
        int a,b;
        cin>>a>>b;
        
         if(g->isBridge(a, b))
            cout<<1<<endl;
        else
             cout<<0<<endl;
         }
}
// } Driver Code Ends


// your task is to complete this function


/*The structure of the class is as follows 
which contains an integer V denoting the no 
of vertices and a list of adjacency vertices.
class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isBridge();
};*/

void DFS(list<int> adj[], bool visited[], int i) {
    if(visited[i]==1) return;
    visited[i] = 1;
    // for(int m=0; m<adj[i].size(); m++) {
    //     if(!visited[adj[i][m]]) {
    //         DFS(adj,visited,adj[i][m]);
    //     }
    // }
    list<int> :: iterator it;
    for(it = adj[i].begin(); it!=adj[i].end(); it++) {
        if(!visited[*it])  DFS(adj,visited,*it);
    }
}

bool Graph::isBridge(int u, int v )
{
  //Code here
  // Adjacency list representation
  // Assuming conected Graph

    list<int> :: iterator it;
    for(it = adj[u].begin(); it!=adj[u].end(); it++) {
        if(*it==v) {
            *it=u;
            break;
        }
    }
    for(it = adj[v].begin(); it!=adj[v].end(); it++) {
        if(*it==u) {
            *it=v;
            break;
        }
    }
    
    bool visited[V] = {false};
    DFS(adj, visited, u);
    if(visited[v]==false) return true;
    
    return false;
}
