/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/kth-largest-element5034/1
*/
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
int KthLargest(int arr[], int n,int k){
    // Your code here
    if(k>n) return -1;
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int i=0; i<k; i++) pq.push(arr[i]);
    for(int i=k; i<n; i++) {
        if(pq.top()<arr[i]) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++)
	        cin >> arr[i];
	    
	    cout << KthLargest(arr, n, k) << endl;
	}
	
	return 0;
}  // } Driver Code Ends
