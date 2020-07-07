/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/count-number-of-hops-1587115620/1
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 
long long countWays(int);
 
int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		cout << countWays(n) << endl;
	}
    
    return 0;
    
}
// } Driver Code Ends
// function to count number of ways to reach top of the stair
long long countWays(int n){
    
    // your code here
    if(n==0 || n==1) return 1;
    if(n==2) return 2;
    long long dp[n+1];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%1000000007;
    }
    return dp[n];
}

