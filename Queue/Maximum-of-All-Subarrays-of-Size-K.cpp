// Problem URL :- https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


void max_of_subarrays(int *arr, int n, int k){
    // your code here
    deque<int> dq;
    for(int i=0; i<k; i++) {
        while(!dq.empty() && arr[dq.back()]<=arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(int i=k; i<n; i++) {
        cout<<arr[dq.front()]<<" ";
        // remove outdated elements
        while(!dq.empty() && dq.front()<=i-k) {
            dq.pop_front();
        }
        // remove smaller elements from the back
        while(!dq.empty() && arr[dq.back()]<=arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<<arr[dq.front()];
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
	    
	    max_of_subarrays(arr, n, k);
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
