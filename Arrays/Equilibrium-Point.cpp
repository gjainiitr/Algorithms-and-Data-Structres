// Problem URL :- https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1

#include <iostream>
using namespace std;

// Position this line where user code will be pasted.

int equilibriumPoint(long long a[], int n);

int main() {

    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long a[n];

        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << equilibriumPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
// Function to find equilibrium point
// a: input array
// n: size of array
int equilibriumPoint(long long a[], int n) {

    // Your code here
    long long lsum[n] = {0};
    long long rsum[n] = {0};
    int i;
    lsum[0] = 0;
    rsum[n-1]=0;
    for(i=1; i<n; i++) {
        lsum[i] = lsum[i-1] + a[i-1];
    }
    for(i=n-2; i>=0; i--) {
        rsum[i] = rsum[i+1] + a[i+1];
    }
    for(i=0; i<n; i++)
        if(lsum[i]==rsum[i]) return i+1;
    if(i==n) return -1;
}
