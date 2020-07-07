/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
*/

// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

/* Function to get minimum number of trials needed in worst 
  case with n eggs and k floors */
int eggDrop(int n, int k) //dp tabulation
{
    // your code here
    if(k==0) return 0;
    if(k==1) return 1;
    if(n==1) return k;
    int dp[n+1][k+1];
    for(int i=0; i<=n; i++) {
        dp[i][0]=0;
        dp[i][1]=1;
    }
    for(int i=0; i<=k; i++) {
        dp[1][i]=i;
    }
    for(int i=2; i<=n; i++) { // i represents n i.e. eggs
        for(int j=2; j<=k; j++) { // j represents k i.e. floors
            dp[i][j]=j;
            for(int p=1; p<j; p++) {
                dp[i][j] = min(dp[i][j], 1+max(dp[i-1][p-1],dp[i][j-p]));
            }
        }
    }
    return dp[n][k];
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;

        cout<<eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
