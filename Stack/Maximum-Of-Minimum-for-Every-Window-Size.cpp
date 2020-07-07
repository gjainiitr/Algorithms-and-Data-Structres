// Problem URL :- https://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1

#include <bits/stdc++.h>
using namespace std;

// Position this line where user code will be pasted.
void printMaxOfMin(int arr[], int n);
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        printMaxOfMin(a, n);
    }
    return 0;
}
// } Driver Code Ends


// Function to print maximum of minimum of every window size
// arr[]: input array
// n: size of array
int max_of_min_of_subarrays(int arr[], int n, int k){
    // your code here
    int maxValue = INT_MIN;
    deque<int> dq;
    for(int i=0; i<k; i++) {
        while(!dq.empty() && arr[dq.back()]>=arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(int i=k; i<n; i++) {
        // cout<<arr[dq.front()]<<" ";
        maxValue = max(maxValue, arr[dq.front()]);
        // remove outdated elements
        while(!dq.empty() && dq.front()<=i-k) {
            dq.pop_front();
        }
        // remove smaller elements from the back
        while(!dq.empty() && arr[dq.back()]>=arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    maxValue = max(maxValue, arr[dq.front()]);
    // cout<<arr[dq.front()];
    return maxValue;
}

void printMaxOfMin(int arr[], int n) {
    for(int i=1; i<=n; i++) {
        cout<<max_of_min_of_subarrays(arr,n,i)<<" ";
    }
    cout<<endl;
}
