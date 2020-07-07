/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/black-and-white-1587115620/1
*/
// { Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

long long solve(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << solve(n, m) << endl;
    }
    return 0;
}// } Driver Code Ends

long long safeCombinations(int i, int j, int m, int n) {
    int unsafe=1;
    if(j+2<m) {
        if(i+1<n) unsafe++;
        if(i-1>=0) unsafe++;
    }
    if(j-2>=0) {
        if(i+1<n) unsafe++;
        if(i-1>=0) unsafe++;
    }
    if(i-2>=0) {
        if(j+1<m) unsafe++;
        if(j-1>=0) unsafe++;    
    }
    if(i+2<n) {
        if(j+1<m) unsafe++;
        if(j-1>=0) unsafe++;
    }
    // long long ans
    return (m*n-unsafe)%1000000007;
}

long long solve(int n, int m) {
    // write code here
    long long res=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            res = (res+safeCombinations(i,j,m,n))%1000000007;
        }
    }
    return res;
}
