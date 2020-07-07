/*
	Problem URL:- https://practice.geeksforgeeks.org/problems/level-of-nodes-1587115620/1
*/
#include <bits/stdc++.h>
using namespace std;

class Graph 
{ 
	int V; 
	vector<int> *adj; 
    
public: 
    Graph(int V); 
	void addEdge(int u, int v); 
	int levels(int x, int in); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new vector<int>[V+1]; 
} 

void Graph::addEdge(int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 


 // } Driver Code Ends

// x is the current level
// in is the no. whose parent is to be found
// Based on BFS, not a recursive function
int Graph::levels( int x, int in){
    // Your code here
    bool visited[V];
    for(int i=0; i<V; i++) visited[i]=false;
    
    queue<int> q;
    q.push(0);
    visited[0] = true;
    
    int currLevel = 0;
    
    while(q.size()>0) {
        int size = q.size();
        for(int i=0; i<size; i++) {
                
            int temp = q.front();
            q.pop();
            if(temp==in) return currLevel;
            for(int m:adj[temp]) {
               if(visited[m]==false) {
                   visited[m]=true;
                   q.push(m);
               } 
            }
        }
        currLevel++;
    }
}



// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, e;
	    cin >> n >> e;
	    Graph g(n);
	    int u, v;
	    for(int i = 0;i<e;i++){
	        cin >> u >> v;
	        g.addEdge(u, v);
		}
	    
	    int x;
	    cin >> x;
	    
	    if(x >= n) cout << "-1" << endl;
	    else
	        cout << g.levels( 0, x) << endl;
	    
	}
	
	return 0;
}
  // } Driver Code Ends
