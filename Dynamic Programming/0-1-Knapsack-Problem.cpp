/*
	Problem URL:- https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Returns the maximum value that  
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) // dp tabulation
{   
    int dp[n+1][W+1];
    
    for(int i=0; i<=n; i++) dp[i][0]=0;
    for(int i=0; i<=W; i++) dp[0][i]=0;
    
    for(int i=1; i<=n; i++) { // i represents no. of items from array
        for(int j=1; j<=W; j++) { // j represents knapSack capacity
            dp[i][j] = dp[i-1][j];
            if(j-wt[i-1]>=0) dp[i][j] = max(dp[i][j], val[i-1]+dp[i-1][j-wt[i-1]]);
        }
    }
    return dp[n][W];
}


// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n, w;
        cin>>n>>w;
        int val[n];
        int wt[n];
        
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
