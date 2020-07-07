/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/largest-sum-contiguous-subarray-in-range/0
*/
#include<bits/stdc++.h>
using namespace std;
struct node {
    int a,b,c,d;
    node(int one=0, int two=0, int three=0, int four=0) {
        a = one;
        b = two;
        c = three;
        d = four;
    }
};
node buildTree(struct node tree[], int arr[], int l, int r, int segIdx) {
    if(l==r) {
        tree[segIdx].a = arr[l];
        tree[segIdx].d = arr[l];
        if(arr[l]>0) {
            tree[segIdx].b = arr[l];
            tree[segIdx].c = arr[l];
        } else {
            tree[segIdx].b = 0;
            tree[segIdx].c = 0;
        }
        return tree[segIdx];
    }
    int mid = (l+r)/2;
    node left = buildTree(tree,arr,l,mid,2*segIdx+1);
    node right = buildTree(tree,arr,mid+1,r,2*segIdx+2);
    
    tree[segIdx].d = left.d + right.d;
    tree[segIdx].b = max(left.b, left.d+right.b);
    tree[segIdx].c = max(right.c, right.d+left.c);
    tree[segIdx].a = max(left.a,right.a);
    if(left.c + right.b >0) {
        tree[segIdx].a = max(tree[segIdx].a, left.c+right.b);
    }
    
    return tree[segIdx];
}
bool isDummy(node temp) {
    if(temp.a==0 && temp.b==-1 && temp.c==-1 && temp.d==0) return true;
    return false;
}
node query(node tree[], int as, int ae, int qs, int qe, int segIdx) {
    if(qe<as || ae<qs) {
        node temp;
        temp.b = -1;
        temp.c = -1;
        return temp;
    }
    if(qs<=as && ae<=qe) {
        return tree[segIdx];
    }
    int mid = (as+ae)/2;
    node left = query(tree,as,mid,qs,qe,2*segIdx+1);
    node right = query(tree,mid+1,ae,qs,qe,2*segIdx+2);
    if(isDummy(left)) return right;
    if(isDummy(right)) return left;
    node temp;
    temp.d = left.d + right.d;
    temp.b = max(left.b, left.d+right.b);
    temp.c = max(right.c, right.d+left.c);
    temp.a = max(left.a,right.a);
    if(left.c + right.b >0) {
        temp.a = max(temp.a, left.c+right.b);
    }
    
    return temp;
}
node update(node tree[], int as, int ae, int idx, int value, int segIdx) {
    if(idx<as || ae<idx) return tree[segIdx];
    if(as==ae && as==idx) {
        tree[segIdx].d = value;
        tree[segIdx].a = value;
        if(value>0) {
            tree[segIdx].b = value;
            tree[segIdx].c = value;
        } else {
            tree[segIdx].b = 0;
            tree[segIdx].c = 0;
        }
        return tree[segIdx];
    }
    if(as==ae) return tree[segIdx];
    if(as<ae) {
        int mid = (as+ae)/2;
        node left = update(tree,as,mid,idx,value,2*segIdx+1);
        node right = update(tree,mid+1,ae,idx,value,2*segIdx+2);
        
        // if(isDummy(left)) return right;
        // if(isDummy(right)) return left;
        
        tree[segIdx].d = left.d + right.d;
        tree[segIdx].b = max(left.b, left.d+right.b);
        tree[segIdx].c = max(right.c, right.d+left.c);
        tree[segIdx].a = max(left.a,right.a);
        if(left.c + right.b >0) {
            tree[segIdx].a = max(tree[segIdx].a, left.c+right.b);
        }
        return tree[segIdx];    
    }
}
int main() { // 1 based indexing used
    int t;
    cin>>t;
    for(int cs=0; cs<t; cs++) {
        int n,q;
        cin>>n>>q;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        int size = 2*(pow(2,(ceil(log(n)/log(2)))))-1;   
        struct node tree[size];
        buildTree(tree,arr,0,n-1,0);
        
        // testing
            // for(int i=0; i<size; i++) cout<<tree[i].a<<" ";
            // cout<<endl;
        //
        
        int type,first,second;
        for(int i=0; i<q; i++) {
            cin>>type>>first>>second;
            if(type==1) {
                cout<<(query(tree,0,n-1,first-1,second-1,0).a)<<endl;
            } else if(type==2) {
                arr[first-1] = second;
                update(tree,0,n-1,first-1,second,0);
            }
        }
    }
    return 0;
}
