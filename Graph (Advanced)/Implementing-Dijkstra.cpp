/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
*/

#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<int>> , int ,int );


int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        dijkstra(g, s, V);
        cout<<endl;
       }
        return 0;
}// } Driver Code Ends


/*  Function to implement Dijkstra
*   graph: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
struct node {
    int vertex;
    int distance;
    node(int v, int d) {
        vertex = v;
        distance = d;
    }
};
class myComparator {
    public :
    bool operator() (struct node n1, struct node n2) {
        return n1.distance>n2.distance;
    }
};
void dijkstra(vector<vector<int>> graph, int src, int V)
{
    // Your code here
    int dist[V];
    bool visited[V]={0};
    for(int i=0; i<V; i++) dist[i]=INT_MAX;
    dist[src]=0;
    
    priority_queue<node, vector<node>, myComparator> pq;
    pq.push(node(src,0));
    while(pq.empty()==false) {
        node temp = pq.top();
        pq.pop();
        int vertex = temp.vertex;
        if(visited[vertex]==1) continue;
        visited[vertex] = 1;
        int distance = temp.distance;
        for(int i=0; i<V; i++) {
            if(graph[vertex][i]!=0) {
                if(!visited[i]) {
                    if(dist[i] > distance + graph[vertex][i]) {
                        dist[i] = distance + graph[vertex][i];
                    }
                    pq.push(node(i,dist[i]));
                }
            }
        }
    }
    for(int i=0; i<V; i++) cout<<dist[i]<<" ";
}
