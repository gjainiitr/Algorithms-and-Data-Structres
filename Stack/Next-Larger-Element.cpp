// Problem URL :- https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to store Next larger elements


void nextLargerElement(long long arr[], int n){
    // Your code here
    stack<long long int> s;
    long long int arr2[n];
   s.push(arr[n-1]); arr2[n-1]=-1;
   for(int i=n-2; i>=0; i--) {
       while(!s.empty()) {
           if(s.top()<=arr[i]) s.pop();
           else break;
       }
       if(s.empty()) arr2[i]=-1;
       else arr2[i]=s.top();
       s.push(arr[i]);
   }
   for(int i=0; i<n; i++) cout<<arr2[i]<<' ';
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        
        nextLargerElement(arr, n);
        
        cout<<endl;
    }
	return 0;
}
  // } Driver Code Ends
