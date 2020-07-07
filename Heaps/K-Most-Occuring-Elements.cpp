/*
	Problem URL:- https://practice.geeksforgeeks.org/problems/most-occurring-elements-1587115620/1
*/

// {
	#include<bits/stdc++.h>
	using namespace std;
 // } Driver Code Ends
// Function to print the k numbers with most occurrences 
int print_N_mostFrequentNumber(int arr[], int n, int k) 
{ 
	// Your code here
	unordered_map<int,int> m;
	for(int i=0; i<n; i++) {
	    if(m.find(arr[i])==m.end()) {
	        m[arr[i]]=1;
	    } else {
	        m[arr[i]] = m[arr[i]] + 1;
	    }
	}
	priority_queue<int> pq;
	for(auto it=m.begin(); it!=m.end(); it++) pq.push(it->second);
	
	int count=0;
	for(int i=0; i<k; i++) {
	    count+=pq.top();
	    pq.pop();
	}
	return count;
} 

// { Driver Code Starts.
// Driver program to test above 
int main() 
{
	int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n;
        int arr[n];
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        cin >> k;
        cout << print_N_mostFrequentNumber(arr, n, k) << endl; 
    }

	return 0; 
} 
  // } Driver Code Ends
