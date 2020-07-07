/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1
*/
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The Graph structure is as folows

// Function to print graph
// adj: array of vectors to represent graph
// V: number of vertices
void printGraph(vector<int> adj[], int V)
{
    // Your code here
    for(int i=0; i<V; i++) {
        int size = adj[i].size();
        cout<<i;
        for(int j=0; j<size; j++) {
            cout<<"-> "<<adj[i][j];
        }
        cout<<endl;
    }
}


// { Driver Code Starts.

int main()
{  
   int t;
   cin>>t;
   while(t--)
    {  int v, e;
       cin>>v>>e;
       int a, b;
       vector<int> adj[v];
       for(int i=0;i<e;i++)
       {
 		    cin>>a>>b;
 		    adj[a].push_back(b);
 		    adj[b].push_back(a);
       }
		printGraph(adj, v);
       
     }
    return 0;
}

  // } Driver Code Ends