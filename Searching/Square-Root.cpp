// Problem URL :- https://practice.geeksforgeeks.org/problems/square-root/1

#include<bits/stdc++.h>
using namespace std;
long long int floorSqrt(long long int x) {
	long long int i;
	for(i=1;i*i<=x;i++);
	return i-1;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		long long int x;
		cin>>x;
		cout<<floorSqrt(x)<<endl;
	}
}
