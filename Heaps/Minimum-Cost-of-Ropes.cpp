/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
*/
#include <bits/stdc++.h>
using namespace std;

// Position this line where user code will be pasted.
long long minCost(long long arr[], long long n);
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << minCost(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
long long minCost(long long arr[], long long n) {
    // Your code here
    priority_queue<long long, vector<long long>, greater<long long>> pq(arr, arr+n); // min heap
    long long count=0,result;
    
    long long high,secHigh;
    while(pq.size()>1) {
        high = pq.top();
        pq.pop();
        secHigh=pq.top();
        pq.pop();
        result = high + secHigh;
        pq.push(result);
        count+=result;
    }
    return count;
}
	
