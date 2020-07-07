// Problem URL :- https://practice.geeksforgeeks.org/problems/union-of-two-arrays/0

#include <bits/stdc++.h>
using namespace std;

int intersection(int arr1[],int arr2[],int n1, int n2) {
    unordered_set<int> s;
    
    int count=0;
    for(int i=0; i<n1; i++) s.insert(arr1[i]);
    for(int j=0; j<n2; j++) s.insert(arr2[j]);
    return s.size();
    // return count;
}


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n1,n2;
	    cin>>n1>>n2;
	    int arr1[n1],arr2[n2];
	    for(int i=0;i<n1;i++)
	        cin>>arr1[i];
	    for(int i=0;i<n2;i++)
	        cin>>arr2[i];
	   // sort(arr1, arr1+n1);
	   // sort(arr2, arr2+n2);
	    cout<<intersection(arr1,arr2,n1,n2);
	    
	    cout<<endl;
	    
	}
	return 0;
}//
