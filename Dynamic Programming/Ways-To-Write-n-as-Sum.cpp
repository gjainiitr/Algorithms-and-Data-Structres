/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/ways-to-write-n-as-sum-1587115621/1
*/

#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int countWays(int);

// Driver program
int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin>>n;
        cout<<countWays(n)<<endl;
    }
    return 0;
}// } Driver Code Ends
// function to count number of ways in which n can
// be written as sum of two or more than two integers
int countWays(int n)
{
    // your code here
    int dp[n+1] = {0};
    dp[0]=1;
    for(int i=1; i<n; i++)
        for(int j=i; j<=n; j++) {
            dp[j] = (dp[j]%mod + dp[j-i]%mod)%mod;
        }
    return dp[n];
}
