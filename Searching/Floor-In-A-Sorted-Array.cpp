// Problem URL :- https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to find floor of x
// n: size of vector
// x: element whose floor is to find
int findFloor(vector<long long> v, long long n, long long x){
    
    // Your code here
    int high = n-1, low = 0, mid,ans;
    if((v[0]>x)) return -1;
    while(high>=low) {
        mid = low + (high-low)/2;
        if(v[mid] == x) return mid;
        else if (v[mid]<x) {
            ans = v[mid];
            low = mid + 1;
        } else high = mid-1;
    }
}

// { Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    
	    cout << findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}  // } Driver Code Ends
