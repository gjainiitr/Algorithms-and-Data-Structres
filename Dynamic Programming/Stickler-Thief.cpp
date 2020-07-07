/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


 // } Driver Code Ends
// Function to return maximum of sum without adjacent elements
ll FindMaxSum(ll arr[], ll n) // dp tabulation
{
    // Your code here
    if(n==1) return arr[0];
    if(n==2) return max(arr[1],arr[0]);
    ll dp[n+1]={0};
    dp[1]=arr[0];
    dp[2]=max(arr[0],arr[1]);
    for(int i=3; i<=n; i++) {
        dp[i] = max(dp[i-1], arr[i-1]+dp[i-2]);
    }
    return dp[n];
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;++i)
			cin>>a[i];
		cout<<FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
