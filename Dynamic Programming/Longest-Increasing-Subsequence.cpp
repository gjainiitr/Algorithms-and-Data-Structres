/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
*/

// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];

        cout << longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends

// Function to find longest subsequence
int longestSubsequence(int n, int a[]){
    
   // your code here
   int dp[n];
   for(int i=0; i<n; i++) dp[i]=1;
   dp[0] = 1;
   for(int i=1; i<n; i++) {
       for(int j=0; j<i; j++) {
           if(a[j]<a[i]) {
               dp[i] = max(dp[i], 1+dp[j]);
           }
       }
   }
    int res=1;
    for(int i=0; i<n; i++) res = max(res,dp[i]);
    return res;
}

