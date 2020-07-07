// Problem URL :- https://practice.geeksforgeeks.org/problems/check-if-two-arrays-are-equal-or-not/0

#include <bits/stdc++.h>
using namespace std;

int areEqual(long long int arr1[],long long int arr2[],long long int n) {
    unordered_map<int,int> m;
    for(int i=0; i<n; i++) m[arr1[i]]++;
    for(int j=0; j<n; j++) m[arr2[j]]--;
    for(auto it=m.begin(); it!=m.end(); it++) {
        if(it->second) return 0;
    }
    return 1;
    // sort(arr1, arr1+n);
    // sort(arr2, arr2+n);
    // for(int i=0; i<n; i++) {
    //     if(arr1[i]!=arr2[i]) return 0;
    // }
    // return 1;
}


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n;
	    cin>>n;
	    long long int arr1[n],arr2[n];
	    for(int i=0;i<n;i++)
	        cin>>arr1[i];
	    for(int i=0;i<n;i++)
	        cin>>arr2[i];
	   // sort(arr1, arr1+n1);
	   // sort(arr2, arr2+n2);
	    cout<<areEqual(arr1,arr2,n);
	    
	    cout<<endl;
	    
	}
	return 0;
}//
