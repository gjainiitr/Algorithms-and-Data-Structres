/*
	Problem URL:- https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


int max(int a, int b) {
    if(a>b) return a;
    return b;
}
int min(int a, int b) {
    if(a>b) return b;
    return a;
}
long long maximumAmount(int arr[], int n) // dp tabulation 
{
    if(n==1) return arr[0];
    if(n==2) return max(arr[0],arr[1]);
    int dp[n][n];
    for(int i=0; i<n-1; i++) dp[i][i+1]=max(arr[i],arr[i+1]);
    for(int gap=3; gap<n; gap+=2) {
        for(int i=0; i+gap<n; i++) {
            int j= i+gap;
            dp[i][j] = max(
                arr[i] + min(dp[i+2][j],dp[i+1][j-1]),
                arr[j] + min(dp[i][j-2],dp[i+1][j-1])
            );
        }
    }
    return dp[0][n-1];
}


// { Driver Code Starts.

int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int N;
	    cin>>N;
	    
	    int A[N];
	    
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    cout<<maximumAmount(A,N)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends
