// Problem URL :- https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

// {
#include<bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int max(int a, int b) {
    if(a>b) return a;
    return b;
}

int maxSubarraySum(int arr[], int n){
    int sum=0,res=INT_MIN;
    // Your code here
    for(int i=0; i<n; i++) {
        if(sum<0) sum=0;
        sum+=arr[i];
        res = max(sum, res);
    }
    return res;
}

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends
