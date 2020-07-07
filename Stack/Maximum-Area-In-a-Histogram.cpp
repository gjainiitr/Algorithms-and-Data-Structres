// Problem URL :- https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Maximum Rectangular area in a histogram
// arr[]: input array
// n: size of array
int max(int a, int b) {
    if(a>b) return a;
    return b;
}
long getMaxArea(long long arr[], int n){
    
    // Your code here
    stack<int> s; long long int curr, out=0,m;
    int i;
    for(i=0; i<n; i++) {
        while(!s.empty()&&arr[s.top()]>=arr[i]) {
            m=s.top(); s.pop();
            curr=arr[m]*(s.empty()?i:i-s.top()-1);
            out=max(out,curr);
        }
        s.push(i);
    }
    while(!s.empty()) {
        m=s.top(); s.pop();
        curr=arr[m]*(s.empty()?n:n-s.top()-1);
        out=max(out,curr);
    }
    return out;
}

// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout<<getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends
