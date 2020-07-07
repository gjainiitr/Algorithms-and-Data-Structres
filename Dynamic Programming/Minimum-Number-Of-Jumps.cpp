/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
*/

 #include <bits/stdc++.h>
using namespace std;
int noOfJumps(int arr[], int n) { // dp tabulation
    if(n==1) return 0;
    if(arr[0]==0) return -1;
    int dp[n+1];
    for(int i=0; i<=n; i++) dp[i]=INT_MAX;
    dp[0]=0;
    dp[1]=0;
    for(int i=2; i<=n; i++) {
        for(int j=0; j<i-1; j++) {
            if(j+arr[j]>=i-1) {
                dp[i] = min(dp[i],1+dp[j+1]);
            }
        }
    }
    if(dp[n]==INT_MAX) return -1;
    else return dp[n];
}
int main() {
	//code
	int t;
	cin>>t;
	for(int cs=0; cs<t; cs++) {
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++) cin>>arr[i];
	    cout<<noOfJumps(arr,n)<<endl;
	}
	return 0;
}
