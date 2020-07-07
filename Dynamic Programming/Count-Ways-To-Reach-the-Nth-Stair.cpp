/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

long long countWays(int);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m;
        cin>>m;
        cout<<countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
// } Driver Code Ends
// function to count ways to reach nth stair
long long countWays(int n) {
    if(n==0) return 1;
    if(n==1) return 1;
    if(n==2) return 2;
    long long dp[n+1];
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=n; i++) dp[i] = (dp[i-1] + dp[i-2])%mod;
    return dp[n];
}
