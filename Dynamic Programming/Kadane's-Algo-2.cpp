/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/kadanes-algorithm-ii/1
*/
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

//Complete this function
long long maximumSum(int arr[], int n) // recursive solution
{
  //Your code here
  if(n==1) return arr[0];
  if(n==2) return max(arr[0],arr[1]);
  
  int dp[n+1]={0};
  dp[0] = 0;
  dp[1] = arr[0];
  // i represents size n;
  for(int i=2; i<=n; i++) {
      int a = dp[i-1];
      int b = arr[i-1] + dp[i-2];
      a = max(a,b);
      dp[i] = max(a,arr[i-1]);
  }
  return dp[n];
}


// { Driver Code Starts.


int main() {
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    int sizeOfArray;
	    cin>>sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    
	    cout<<maximumSum(arr,sizeOfArray)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends
