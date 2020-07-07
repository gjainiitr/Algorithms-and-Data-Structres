// Problem URL :- https://practice.geeksforgeeks.org/problems/maximum-water-between-two-buildings/1

//Initial Template for C++


// C++ implementation of the approach 
#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends

//User function Template for C++


// Return the maximum water that can be stored 
int maxWater(int height[], int n) 
{ 
    //Your code here
    if(n<=2) return 0;
    int res=0;
    int i=0,j=n-1;
    while(j-i>1) {
        res = max(res,min(height[i],height[j])*(j-i-1));
        if(height[i]<height[j]) i++;
        else j--;
    }
    return res;
} 



// { Driver Code Starts.

// Driver code 
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int height[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>height[i];
        }
        
        cout<<(maxWater(height, n))<<endl;
    }

	 
} 

  // } Driver Code Ends
