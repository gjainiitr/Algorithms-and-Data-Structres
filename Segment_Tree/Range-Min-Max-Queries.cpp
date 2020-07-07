/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/range-min-max-queries/0
*/
#include<bits/stdc++.h>
using namespace std;
pair<int,int> makeTree(pair<int,int> *pointer, int arr[], int l, int r, int segIdx) {
    if(l==r) {
        pointer[segIdx].first = arr[l];
        pointer[segIdx].second = arr[l];
        return pointer[segIdx];
    }
    int mid = (l+r)/2;
    pair<int,int> temp1 = makeTree(pointer,arr,l,mid,2*segIdx+1);
    pair<int,int> temp2 = makeTree(pointer,arr,mid+1,r,2*segIdx+2);
    pointer[segIdx].first = min(temp1.first,temp2.first);
    pointer[segIdx].second = max(temp1.second,temp2.second);
    return pointer[segIdx];
}
pair<int,int>* buildTree(int arr[], int n, int size) {
    pair<int,int> *pointer = new pair<int,int>[size];
    makeTree(pointer,arr,0,n-1,0);
    return pointer;
}
pair<int,int> query(pair<int,int> *arr, int as, int ae, int qs, int qe, int segIdx) {
    if(qe<as || ae<qs) {
        pair<int,int> p(INT_MAX,INT_MIN);
        return p;
    };
    if(qs<=as && ae<=qe) return arr[segIdx];
    int mid=(as+ae)/2;
    pair<int,int> temp1 = query(arr,as,mid,qs,qe,2*segIdx+1);
    pair<int,int> temp2 = query(arr,mid+1,ae,qs,qe,2*segIdx+2);
    pair<int,int> temp;
    temp.first = min(temp1.first,temp2.first);
    temp.second = max(temp1.second,temp2.second);
    return temp;
}
// #################################################################################################
pair<int,int> update(pair<int,int>* arr, int as, int ae, int idx, int value,int segIdx) {
    if(idx<as || ae<idx) {
        return arr[segIdx];
        // return p;
    }
    if(as==ae && as==idx) {
        arr[segIdx].first = value;
        arr[segIdx].second = value;
        return arr[segIdx];
    }
    if(as<ae) {
        int mid=(as+ae)/2;
        pair<int,int> temp1 = update(arr,as,mid,idx,value,2*segIdx+1);
        pair<int,int> temp2 = update(arr,mid+1,ae,idx,value,2*segIdx+2);
        arr[segIdx].first = min(temp1.first,temp2.first);
        arr[segIdx].second = max(temp1.second,temp2.second);
        return arr[segIdx];
    }
}
// #################################################################################################
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
	    pair<int,int>* arr = buildTree(arr2,n,size);
	   // for(int i=0; i<size; i++) cout<<arr[i]<<" ";
	   // cout<<endl;
	   //#######################################################################
	    for(int i=0; i<q; i++) {
	        cin>>identifier;
	        int l,r;
	        int idx, value, diff;
	        if(identifier=='G') {
	            cin>>l>>r;
	            pair<int,int> temp = query(arr,0,n-1,l,r,0); 
	            cout<<temp.first<<" "<<temp.second<<endl;
	        } else if(identifier=='U') {
	            cin>>idx>>value;
	            arr2[idx] = value;
	            update(arr,0,n-1,idx,value,0);
	        }
	    }
	   //#######################################################################
	}
	return 0;
}
