/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/print-first-n-fibonacci-numbers/0
*/

#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	for(int cases=0; cases<t; cases++) {
	    int n;
	    cin>>n;
	    if(n==1) {
	        cout<<1<<endl;
	        continue;
	    }
	    if(n==2) {
	        cout<<1<<" "<<1<<endl;
	        continue;
	    }
	    long long arr[n];
	    arr[0]=1;
	    arr[1]=1;
	    for(int i=2; i<n; i++) {
	        arr[i] = arr[i-1] + arr[i-2];
	    }
	    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
