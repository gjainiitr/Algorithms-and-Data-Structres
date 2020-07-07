/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

#define SIZE 100


 // } Driver Code Ends


/*  Function to find the area of 1s
*   SIZE: declared globally for matrix definition
*   n, m: row and column of matrix
*   g[][]: 2D matrix from input
*/
void checkForIslands(int A[SIZE][SIZE], int N, int M, int i, int j, vector<bool> visited[],int &out) {
    if(i<0 || j<0) return;
    if(i>=N || j>=M) return;
    // if(A[i][j]==0) return;
    visited[i][j] = 1;
    out+=1;
    // bool shouldIncrease = true;
    for(int p=i-1; p<=i+1; p++) {
        for(int q=j-1; q<=j+1; q++) {
            if(p<0 || p>=N) continue;
            if(q<0 || q>=M) continue;
            if(p==i && q==j) continue;
            // if(A[p][q]==0) visited[p][q]=true;
            // if(A[p][q]==true && visited[p][q]==true) shouldIncrease=false;
            if(A[p][q]==1 && visited[p][q]==false) {
                checkForIslands(A,N,M,p,q,visited,out);
            } 
        }
    }
}
int findMaxArea(int N, int M, int A[SIZE][SIZE] )
{
    // Your code here
    int res=0;
    int out;

    vector<bool> visited[N];
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) visited[i].push_back(0);
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(A[i][j]==0) visited[i][j]=1;
            if(!visited[i][j] && A[i][j]==1) {
                out=0;
                checkForIslands(A, N, M, i, j, visited,out);
                res = max(res,out);
            }
        }
    }
   
    return res;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int g[SIZE][SIZE];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> g[i][j];

        cout << findMaxArea(n, m, g) << endl;
    }

    return 0;
}  // } Driver Code Ends
