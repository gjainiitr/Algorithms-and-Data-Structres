//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


/*
Problem URL :- https://practice.geeksforgeeks.org/problems/union-find/1
*/

 // } Driver Code Ends

//User function Template for C++


/* This function does union of 2 nodes a and b */
// a : node 1 
// b : node 2
// par : empty array (n+1) size with all elements as i
// rank1 : empty array (n+1) size with all elements as 1
int find(int x, int par[]) {
    if(x==par[x]) return x;
    else {
        par[x] = find(par[x], par);
        return par[x];
    }
}
void union_( int a, int b, int par[], int rank1[]) {
    int a_rep = find(a,par);
    int b_rep = find(b,par);
    if(a_rep==b_rep) return;
    else {
        if(rank1[a_rep]>rank1[b_rep]) {
            par[b_rep] = a_rep;
            rank1[b_rep] += 1;
        } else {
            par[a_rep] = b_rep;
            rank1[a_rep] += 1;
        }
        return;
    }
}


/* This function checks whether 2 nodes x and y are connected or not */
// x : node 1 
// y : node 2
// par : empty array (n+1) size with all elements as i
// rank1 : empty array (n+1) size with all elements as 1
bool isConnected(int x,int y, int par[], int rank1[]) {
    int a_rep = find(x,par);
    int b_rep = find(y,par);
    if(a_rep==b_rep) return true;
    return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        
        int par[n+1];
        int rank1[n+1];

        for(int i=1; i<=n; i++) {
            par[i] = i;
            rank1[i] = 1;
    }
    
    int q;
    cin>>q;
    while(q--) {
        int a,b;
        char c;
        cin>>c>>a>>b;
        if(c=='U')
        {
            union_(a,b, par, rank1);
        }
        else
        cout<<isConnected(a,b, par, rank1)<<endl;
    }
    }
    return 0;
}
  // } Driver Code Ends
