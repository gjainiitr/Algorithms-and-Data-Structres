/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/max-sum-subarray-by-removing-at-most-one-element/1
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int maxSumSubarray(int [], int );

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		cout<<maxSumSubarray(a,n)<<endl;
	}
}

// } Driver Code Ends
/*You are required to complete below method */
int maxSumSubarray(int arr[], int n)
{
    //Your code here
    if(n==1) return arr[0];
    int dp[n], dp2[n];
    dp[0] = arr[0];
    int res=max(arr[0],arr[n-1]);
    for(int i=1;i<n;i++)
   {
       
    //   int temp = dp[i-1] + arr[i];
       dp[i] = max(arr[i], dp[i-1]+arr[i]);
       res = max(res, dp[i]); // includes the case when we leave no element behind
   }
   dp2[n-1] = arr[n-1];
   for(int i=n-2; i>=0; i--) {
       dp2[i]=max(arr[i],arr[i]+dp2[i+1]);
   }
   for(int i=1; i<n-1; i++) {
       res = max(res, dp[i-1]+dp2[i+1]);
   }
    return res;
}
