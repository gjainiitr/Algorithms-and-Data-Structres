/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/nth-catalan-number/0
*/

#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
using boost::multiprecision::cpp_int;
using namespace std;
cpp_int nthCatalan(int n) {
    cpp_int res=1;
    for(int i=0; i<n; i++) {
        res *= (2*n)-i;
        res /= i+1;
    }
    // long long res = num/den;
    res = res/(n+1);
    return res;
}
int main() {
	//code
	int t;
    cin>>t;
    for(int c=0; c<t; c++) {
        int n;
        cin>>n;
        cout<<nthCatalan(n)<<endl;
    }
	return 0;
}
