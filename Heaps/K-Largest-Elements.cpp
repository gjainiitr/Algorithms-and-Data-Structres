/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/k-largest-elements3736/1
*/
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

void kLargest(int arr[], int n, int k){
    // your code here
    if(k>=n) return;
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int i=0; i<k; i++) pq.push(arr[i]);
    for(int i=k; i<n; i++) {
        if(pq.top()<arr[i]) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    vector<int> v;
    int size = pq.size();
    for(int i=0; i<size; i++) {
        v.push_back(pq.top());
        pq.pop();
    }
    for(int i=k-1; i>=0; i--) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}


// { Driver Code Starts.
void kLargest(int arr[], int n, int k);

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        for(int i = 0; i < n;i++)
            cin>>arr[i];
        
        kLargest(arr, n, k);
        
    }
    return 0;
}  // } Driver Code Ends
