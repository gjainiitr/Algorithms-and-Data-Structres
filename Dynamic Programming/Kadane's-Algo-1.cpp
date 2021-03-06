/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/kadanes-algorithm-i/1
*/
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
//Complete this function
long long maximumSum(int arr[], int sizeOfArray)
{
   long long dp[sizeOfArray]={0}; //declaring dp array 
   dp[0]=arr[0]; //the first element is maximum till now
   long long answer=arr[0];
   for(int i=1;i<sizeOfArray;i++)
   {
       //The maximum sum at dp[i] will be max of (current array element+dp[i-1]) and (current array element)
       //Complete this code
       int temp = dp[i-1] + arr[i];
       dp[i] = max(arr[i], temp);
       answer=max(answer,dp[i]);
   }
   //To print the dp array
   for(int i=0;i<sizeOfArray;i++)
   {
       cout<<dp[i]<<" ";
   }
   cout<<endl;
   //Printing over
   
   return answer;
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
