/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/reach-a-given-score/0
*/
#include <iostream>
using namespace std;
int ways(int sum) {
    int n=3;
    int arr[n] = {3,5,10};
    int dp[sum+1]={0}; 
    dp[0]=1;
    for(int i=1; i<=n; i++) {
        for(int j=arr[i-1]; j<=sum; j++) {
            dp[j] += dp[j-arr[i-1]];
        }
    }
    return dp[sum];
}
int main() {
	//code
	int t;
	cin>>t;
	for(int cs=0; cs<t; cs++) {
	    int n;
	    cin>>n;
	    cout<<ways(n)<<endl;
	}
	return 0;
}

