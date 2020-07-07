/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/subset-sum-problem/0
*/

#include<bits/stdc++.h>
using namespace std;

bool subsum(int arr[], int n, int sum) { // recursive solution
    // base case
    bool dp[n+1][sum+1];
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=sum; j++) {
            if(j==0) dp[i][j]=true;
            else dp[i][j]=false;
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum; j++) {
            dp[i][j] = dp[i-1][j];
            if(j-arr[i-1]>=0) dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
        }
    }
    return dp[n][sum];
}




// {
int main() {
	//code
	int t;
	cin>>t;
	for(int cs=0; cs<t; cs++) {
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++) cin>>arr[i];
	    int sum=0;
	    for(int i=0; i<n; i++) sum+=arr[i];
	    
        if(sum%2==0 && subsum(arr,n,sum/2)==true) cout<<"YES";
        else cout<<"NO";
	    cout<<endl;
	}
	return 0;
}
// }
