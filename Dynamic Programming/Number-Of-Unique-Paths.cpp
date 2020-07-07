/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/number-of-unique-paths/0
*/

#include<bits/stdc++.h>
using namespace std;
int perm(int m, int n) {
    int res = 1;
    
    m-=1;
    n-=1;
    int total = m+n;
    if(m<n) {
        swap(m,n);
    } // m>n
    for(int i=1; i<=m; i++) {
        res*= i+n;
        res/=i;
    }
    return res;
}
int main() {
	int t;
	cin>>t;
	for(int cs=0; cs<t; cs++) {
	    int m,n;
	    cin>>m>>n;
	    cout<<perm(m,n)<<endl;
	}
	return 0;
}
