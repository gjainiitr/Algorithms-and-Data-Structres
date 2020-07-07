/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream-1587115620/1
*/
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
void kthLargest(int arr[], int n, int k)
{
	// your code here
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=0; i<k; i++) {
	    pq.push(arr[i]);
	}
	for(int i=0; i<k-1; i++) cout<<-1<<" ";
	cout<<pq.top()<<" ";
	for(int i=k; i<n; i++) {
	    if(pq.top()<arr[i]) {
	        pq.pop();
	        pq.push(arr[i]);
	    }
	    cout<<pq.top()<<" ";
	}
}

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k, n;
		cin>>k>>n;
	    
	    int arr[n];
	    for(int i = 0; i<n ; ++i)
	        cin>>arr[i];
    
	    kthLargest(arr, n, k);
	    cout<<endl;
	    
	    
	}
	return 0;
}
  // } Driver Code Ends
