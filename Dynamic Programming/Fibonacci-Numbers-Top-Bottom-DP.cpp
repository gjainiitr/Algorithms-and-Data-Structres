/*
	Problem URL :- 
*/

// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
#include <fstream>
using namespace std;


long long dp[100]={0};


 // } Driver Code Ends
//User function Template for C++

//Complete this function
long long findNthFibonacci(int number)
{
  if(dp[number]>0)
  return dp[number];
  
  //Complete this line. dp[number] is equal to function(n-1)+function(n-2)
  dp[number] = findNthFibonacci(number-1) + findNthFibonacci(number-2);
  return dp[number];
}


// { Driver Code Starts.
long long findNthFibonacci(int number);

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
