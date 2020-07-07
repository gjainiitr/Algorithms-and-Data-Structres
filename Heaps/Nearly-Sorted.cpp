/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1
*/
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
void nearlySorted(int arr[], int n, int k){
    // Your code here
    priority_queue<int, vector<int>, greater<int>> pq(arr,arr+k);
    if(k<n) pq.push(arr[k]);
    for(int i=k+1; i<n; i++) {
        cout<<pq.top()<<" ";
        pq.pop();
        pq.push(arr[i]);
    }
    for(int i=0; i<k; i++) {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    if(k<n) {
        cout<<pq.top();
        pq.pop();
    }
}

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    
	    nearlySorted(arr, num, K);
	    cout<<endl;
	}
	
	return 0;
}
  // } Driver Code Ends
