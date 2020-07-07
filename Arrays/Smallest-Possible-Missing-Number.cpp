// Problem URL :- https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Functio to find first smallest positive
// missing number in the array

int mod(int n) {
    if(n<0) return -1*n;
    else return n;
}
int missingNumber(int arr[], int n) { 
    int result=0,i,k;
    // Your code here
    // replace -ve nos with n
    for(i=0; i<n; i++) {
        if(arr[i]>=(n+1)) arr[i]=n+1;
        if(arr[i]<=0) arr[i]=n+1;
    }
    
    // use array indexing
    for(i=0; i<n; i++) {
        if(arr[i]!=(n+1)) {
            k=mod(arr[i])-1;
            if(arr[k]<0) continue;
            else arr[k]*=-1;
        }
    }
    for(i=0; i<n; i++) {
        if(arr[i]>0) {
            result = i+1;
            break;
        }
    }
    if(result==0) return n+1;
    else return result;

} 

// { Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        cout<<missingNumber(arr, n)<<endl;
    }
    return 0; 
}   // } Driver Code Ends
