/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/unique-bsts-1587115621/1
*/
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

// Functiuon to return number of trees
int numTrees(int n) {
    int dp[n+1]={0};
    dp[0]=1;
    dp[1]=1;
    int mod = 1000000007;
    for(int i=2;i<=n;i++){
        dp[i]=0;
        for(int j=1;j<=i;j++){
            dp[i] = dp[i]+ ((long long)dp[j-1]*dp[i-j])%mod; //converted the product to long long because multiplication of two big integers
            if(dp[i]>=mod)
                dp[i]%=mod;
        }
    }
    return dp[n];
}


// { Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<numTrees(n)<<"\n";
    }
}	  // } Driver Code Ends
