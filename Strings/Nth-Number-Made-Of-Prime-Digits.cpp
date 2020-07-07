// Problem URL :- https://practice.geeksforgeeks.org/problems/nth-number-made-of-prime-digits/0

#include<bits/stdc++.h>
#include<vector>
using namespace std;
void nthPrime(int n) {
    vector<string> v;
    int j=0;
    v.push_back("");
    for(int i=n; i>=0; i-=4) {
        v.push_back(v[j]+"2");
        v.push_back(v[j]+"3");
        v.push_back(v[j]+"5");
        v.push_back(v[j]+"7");
        j++;
    }
    cout<<v[n];
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    nthPrime(n);
	    cout<<endl;
	}
	return 0;
}
