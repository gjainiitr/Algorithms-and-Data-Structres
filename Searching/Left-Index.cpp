// Problem URL :- https://practice.geeksforgeeks.org/problems/left-index-1587115620/1

#include<bits/stdc++.h>
using namespace std;
int leftIndex(int n, int arr[], int key){
	// Your code here
	auto x=find(arr,arr+n,key);
	int index=x-arr;
	if(index==n) return -1;
	else return index;

}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int x;
		cin>>x;
		int arr[x];
		for(int i=0; i<x; i++) cin>>arr[i];
		int key;
		cin>>key;
		cout<<leftIndex(x,arr,key)<<endl;
	}
}
