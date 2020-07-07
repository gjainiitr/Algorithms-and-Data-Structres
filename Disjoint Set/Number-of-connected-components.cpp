//Initial Template for C++
/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/number-of-connected-components/1
*/

#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int rank1[100001];


 // } Driver Code Ends

//User function Template for C++


int find(int x, int arr[]) {
    if(x==arr[x]) return x;
    else {
        arr[x] = find(arr[x], arr);
        return arr[x];
    }
}
int balance(int x, int arr[]) {
    if(x==arr[x]) return x;
    else {
        arr[x] = balance(arr[x],arr);
        return arr[x];
    }
}
/* This function does union of 2 nodes a and b */
// a : node 1 
// b : node 2
// arr : array (n+1) size with elements from 1 to N equal to its index.
// rank1 : array (n+1) size with all elements equal to 1. 
// n : Number of nodes
void unionNodes( int a, int b, int arr[], int rank1[], int n) {
    int a_rep = find(a,arr);
    int b_rep = find(b,arr);
    if(a_rep==b_rep) return;
    else {
        if(rank1[a_rep]>rank1[b_rep]) {
            arr[b_rep] = a_rep;
            rank1[b_rep] += 1;
        } else {
            arr[a_rep] = b_rep;
            rank1[a_rep] += 1;
        }
        return;
    }
}

/* This function returns number of connected components */
// arr : array (n+1) size with elements from 1 to N equal to its index.
// rank1 : array (n+1) size with all elements equal to 1. 
// n : Number of nodes
int findNumberOfConnectedNodes( int n, int arr[], int rank1[]) {
    unordered_set<int> s;
    for(int i=1; i<=n; i++)  balance(i,arr);
    int count=0;
    for(int i=1; i<=n; i++) {
        if(s.find(arr[i])==s.end()) {
            count++;
            s.insert(arr[i]);
        }
    }
    return count;
}

// { Driver Code Starts.



int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        for(int i=1; i<=n; i++) {
            arr[i] = i;
            rank1[i] = 1;
        }

        int q;
        cin>>q;
        while(q--) {
            int a,b;
            cin>>a>>b;
            unionNodes(a,b, arr, rank1, n);
        }

        cout<<findNumberOfConnectedNodes(n, arr, rank1)<<endl;
    }
    return 0;
}  // } Driver Code Ends
