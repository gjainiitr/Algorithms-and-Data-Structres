// Problem URL :- https://practice.geeksforgeeks.org/problems/relative-sorting/0

#include<bits/stdc++.h>
#include<unordered_map>
#include<vector>
using namespace std;
void relativeSorting(int arr1[], int arr2[], int m, int n) {
    vector<int> v;
    unordered_map <int, int> mp;
    
    for(int i=0; i<n; i++) {
        auto it=mp.find(arr2[i]);
        if(it==mp.end()) mp[arr2[i]]=0;
    }
    
    for(int i=0; i<m; i++) {
        auto it=mp.find(arr1[i]);
        if(it!=mp.end()) mp[arr1[i]]=mp[arr1[i]]+1;
        else v.push_back(arr1[i]);
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<mp[arr2[i]]; j++) cout<<arr2[i]<<" ";
    }
    sort(v.begin(),v.end());
    for(auto i=v.begin(); i!=v.end(); i++) {
        cout<<(*i)<<" ";
    }
}
int main() {
	//code
	int t; cin>>t;
	for(int i=0; i<t; i++) {
	    int m,n; cin>>m>>n;
	    int arr1[m],arr2[n];
	    for(int i=0; i<m; i++) cin>>arr1[i];
	    for(int j=0; j<n; j++) cin>>arr2[j];
	    relativeSorting(arr1,arr2,m,n);
	    cout<<endl;
	}
	return 0;
}
