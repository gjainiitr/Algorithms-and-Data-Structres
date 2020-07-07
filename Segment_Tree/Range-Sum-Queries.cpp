/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/range-sum-queries/0
*/
#include<bits/stdc++.h>
using namespace std;
int makeTree(int *pointer, int arr[], int l, int r, int segIdx) {
    if(l==r) {
        pointer[segIdx] = arr[l];
        return arr[l];
    }
    int mid = (l+r)/2;
    pointer[segIdx]= makeTree(pointer,arr,l,mid,2*segIdx+1) + makeTree(pointer,arr,mid+1,r,2*segIdx+2);
    return pointer[segIdx];
}
int * buildTree(int arr[], int n, int size) {
    int *pointer = new int[size];
    makeTree(pointer,arr,0,n-1,0);
    return pointer;
}
int query(int *arr, int as, int ae, int qs, int qe, int segIdx) {
    if(qe<as || ae<qs) return 0;
    if(qs<=as && ae<=qe) return arr[segIdx];
    int mid=(as+ae)/2;
    return query(arr,as,mid,qs,qe,2*segIdx+1)+query(arr,mid+1,ae,qs,qe,2*segIdx+2);
}
void update(int *arr, int as, int ae, int idx, int diff,int segIdx) {
    if(idx<as || ae<idx) return;
    arr[segIdx] += diff;
    if(as>=ae) return;
    int mid=(as+ae)/2;
    update(arr,as,mid,idx,diff,2*segIdx+1);
    update(arr,mid+1,ae,idx,diff,2*segIdx+2);
}
int main() {
	//code
	int t;
	cin>>t;
	for(int cs=0; cs<t; cs++) {
	    int n,q;
	    cin>>n>>q;
	    int arr2[n];
	    int size = 2*(pow(2,(ceil(log(n)/log(2)))))-1;
	    for(int i=0; i<n; i++) cin>>arr2[i];
	    char identifier;
	    int* arr = buildTree(arr2,n,size);
	   // for(int i=0; i<size; i++) cout<<arr[i]<<" ";
	   // cout<<endl;
	   //#######################################################################
	    for(int i=0; i<q; i++) {
	        cin>>identifier;
	        int l,r;
	        int idx, value, diff;
	        if(identifier=='G') {
	            cin>>l>>r;
	            cout<<query(arr,0,n-1,l,r,0)<<endl;
	        } else if(identifier=='U') {
	            cin>>idx>>value;
	            diff = value-arr2[idx];
	            arr2[idx] = value;
	            update(arr,0,n-1,idx,diff,0);
	        }
	    }
	   //#######################################################################
	}
	return 0;
}
