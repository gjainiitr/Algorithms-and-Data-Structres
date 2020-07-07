/*
	Problem URL:- https://practice.geeksforgeeks.org/problems/range-gcd-queries/0
*/
#include<bits/stdc++.h>
using namespace std;
int hcf(int A, int B) {
    if(B==0) return A;
    return hcf(B,A%B);
}
int buildTree(int arr[], int tree[], int l, int r, int segIdx) {
    if(l==r) {
        tree[segIdx] = arr[l];
        return arr[l];
    }
    int mid = (l+r)/2;
    int left = buildTree(arr,tree,l,mid,2*segIdx+1);
    int right = buildTree(arr,tree,mid+1,r,2*segIdx+2);
    tree[segIdx] = hcf(left,right);
    return tree[segIdx];
}
int query(int tree[], int as, int ae, int qs, int qe, int segIdx) {
    if(qe<as || ae<qs) {
        return 0;
    }
    if(qs<=as && ae<=qe) return tree[segIdx];
    int mid = (as+ae)/2;
    return hcf(query(tree,as,mid,qs,qe,2*segIdx+1), query(tree,mid+1,ae,qs,qe,2*segIdx+2));
    // if(left==-1) return right;
    // if(right==-1) return left;
    // return hcf(left,right);
}
// ############################################################################
int update(int tree[], int as, int ae, int idx, int value, int segIdx) {
    if(idx<as || ae<idx) return tree[segIdx];
    if(as==ae && as==idx) {
        tree[segIdx] = value;
        return tree[segIdx];
    }
    if(as==ae) return tree[segIdx];
    if(as<ae) {
        int mid = (as+ae)/2;
        int left = update(tree,as,mid,idx,value,2*segIdx+1);
        int right = update(tree,mid+1,ae,idx,value,2*segIdx+2);
        tree[segIdx] = hcf(left,right);
        return tree[segIdx];
    }
}
// ############################################################################
int main() {
    int t;
    cin>>t;
    for(int cs=0; cs<t; cs++) {
        int n,q;
        cin>>n>>q;
        int arr[n]={0};
        int size = 2*(pow(2,(ceil(log(n)/log(2)))))-1;
        for(int i=0; i<n; i++) cin>>arr[i];
        int tree[size]={0};
        buildTree(arr,tree,0,n-1,0);
        int type,first,second;
        
        // // testing
        // for(int i=0; i<size; i++) cout<<tree[i]<<" ";
        // cout<<endl;
        // //
        
        
        for(int i=0; i<q; i++) {
            cin>>type;
            cin>>first>>second;
            if(type==0) {
                cout<<query(tree,0,n-1,first,second,0)<<endl;
            } else if(type==1) {
                arr[first] = second;
                update(tree,0,n-1,first,second,0);
            }
        }
    }
}
