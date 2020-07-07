/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/strongly-connected-component-tarjanss-algo-1587115621/1
*/

// { Driver Code Starts
#include <bits/stdc++.h>
#define NIL -1
using namespace std;

void find(vector<int> adj[], stack<int> &st, int index[], int lowlink[],
          bool onstack[], int i);

int main() {

    int t; // number of test cases
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m; // n- number of nodes and m- number of edges

        int lowlink[n + 1], index[n + 1];

        // v.index, which numbers the nodes consecutively in the order in which
        // they are discovered
        // v.lowlink that represents the smallest index of any node known to be
        // reachable from v through v's DFS subtree, including v itself.

        vector<int> adj[n + 1]; // adjacency list
        bool onstack[n +
                     1]; // onstack is true if ith node is present on the stack

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }

        stack<int> st;

        for (int i = 0; i < n; ++i) {
            lowlink[i] = -1;
            index[i] = -1;
            onstack[i] = false;
        }

        for (int i = 0; i < n; ++i) {
            if (index[i] ==
                -1) { // index is -1 if the ith node is still not visit

                find(adj, st, index, lowlink, onstack, i); // dfs calling
            }
        }

        cout << "\n";
    }
}// } Driver Code Ends

void DFS(vector<int> adj[], int i, int index[], int &disc, int lowlink[], bool onstack[], stack<int> &st) {
    index[i] = disc;
    lowlink[i] = disc;
    onstack[i] = true;
    st.push(i);
    disc++;
    for(int j=0; j<adj[i].size(); j++) {
        if(index[adj[i][j]] == -1) {
            DFS(adj,adj[i][j], index, disc, lowlink, onstack, st);
            lowlink[i] = min(lowlink[i], lowlink[adj[i][j]]);
        } else {
            if(onstack[adj[i][j]]==true) {
                lowlink[i] = min(lowlink[i], index[adj[i][j]]);
            }
        }
    }
    
    if(lowlink[i]==index[i]) {
        while(st.top() != i) {
            cout<<st.top()<<" ";
            onstack[st.top()] = false;
            st.pop();
        }
        cout<<st.top();
        onstack[st.top()] = false;
        st.pop();
        cout<<",";
    }
    // onstack[i] = false;
}
void find(vector<int> adj[], stack<int> &st, int index[], int lowlink[],
          bool onstack[], int i) {

    // your code here
    int disc=1;
    DFS(adj,i,index,disc,lowlink,onstack,st);
    
}

