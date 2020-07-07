/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/fibonacci-numbers-bottom-up-dp/1
*/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <fstream>
using namespace std;


long long dp[100]={0};

long long findNthFibonacci(int number);

 // } Driver Code Ends
//User function Template for C++


//Complete this function
long long findNthFibonacci(int number)
{
  if(dp[number]>0)
  return dp[number];
  
  for(int i=3;i<=number;i++)
    dp[i] = dp[i-1]+dp[i-2];
  
  return dp[number];
  
}

// { Driver Code Starts.

int main()
 {
    
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    int testcases;
    cin>>testcases;
    
    while(testcases--)
    {
        int number;
        cin>>number;
        cout<<findNthFibonacci(number)<<endl;
    }
    
	return 0;
}
  // } Driver Code Ends
