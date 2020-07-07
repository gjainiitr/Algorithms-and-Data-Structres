/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/cutted-segments1642/1
*/
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z);

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        
        int x,y,z;
        cin>>x>>y>>z;
        
        cout<<maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}// } Driver Code Ends
//Complete this function
int maximizeTheCuts(int n, int x, int y, int z) // dp tabulation
{
    int dp[n+1];
    for(int i=0; i<=n; i++) dp[i]=-1;
    dp[0]=0;
    for(int i=1; i<=n; i++) {
        if(i-x>=0) {
            if(dp[i-x]!=-1) dp[i]=max(dp[i],1+dp[i-x]);
        }
        if(i-y>=0) {
            if(dp[i-y]!=-1) dp[i]=max(dp[i],1+dp[i-y]);
        }
        if(i-z>=0) {
            if(dp[i-z]!=-1) dp[i]=max(dp[i],1+dp[i-z]);
        }
    }
    if(dp[n]<=0) return 0;
    return dp[n];
}
