// Problem URL :- https://practice.geeksforgeeks.org/problems/rearrange-an-array-with-o1-extra-space3142/1

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
    
// Function to rarrange the elements in O(1) extra space
// arr: input array
// n: size of array
void arrange(long long arr[], int n) {
    // Your code here
    int k = n+1, temp;
    for(int i=0; i<n; i++) {
        arr[i] = arr[i]%k + k*(arr[(arr[i]%k)]%k);
    }
    for(int i=0; i<n; i++) arr[i]/=k;
}


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        arrange(A, n);
        for(int i=0;i<n;i++){
            cout << A[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
