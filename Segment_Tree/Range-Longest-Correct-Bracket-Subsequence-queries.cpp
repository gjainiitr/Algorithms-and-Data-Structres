/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/range-queries-for-longest-correct-bracket-subsequence/0
*/
#include<bits/stdc++.h>
using namespace std;
// naive solution i.e. O(n)
// in the next step, just make a tree, that's it;
struct node {
    int pairs;
    int unusedOpen;
    int unusedClosed;
    node(int a=0,int b=0, int c=0) {
        pairs = a;
        unusedOpen = b;
        unusedClosed = c;
    }
};
int checkBalanced(string s, int l, int r) {
    stack<char> sk;
    int res=0;
    for(int i=l; i<=r; i++) {
        if(s[i]=='(') {
            sk.push('(');
        } else if(s[i]==')') {
            if(sk.empty()) {
                continue;
            } else {
                sk.pop();
                res+=2;
            }
        }
    }
    return res;
}
struct node makeTree(string str, struct node tree[],int l,int r,int segIdx) {
    if(l==r) {
        tree[segIdx].pairs=0;
        if(str[l]=='(') {
            tree[segIdx].unusedOpen=1;
            tree[segIdx].unusedClosed=0;
        } else {
            tree[segIdx].unusedOpen=0;
            tree[segIdx].unusedClosed=1;
        }
        return tree[segIdx];
    }
    int mid = (l+r)/2;
    node temp1 = makeTree(str,tree,l,mid,2*segIdx+1);
    node temp2 = makeTree(str,tree,mid+1,r,2*segIdx+2);
    int x = min(temp1.unusedOpen, temp2.unusedClosed);
    tree[segIdx].pairs = temp1.pairs + temp2.pairs + x;
    tree[segIdx].unusedOpen = temp1.unusedOpen + temp2.unusedOpen - x;
    tree[segIdx].unusedClosed = temp1.unusedClosed + temp2.unusedClosed - x;
    return tree[segIdx];
}
struct node query(struct node tree[], int as, int ae, int qs, int qe, int segIdx) {
    if(qe<as || ae<qs) {
        node temp;
        return temp;
    }
    if(qs<=as && ae<=qe) return tree[segIdx];
    int mid = (as+ae)/2;
    node temp1 = query(tree,as,mid,qs,qe,2*segIdx+1);
    node temp2 = query(tree,mid+1,ae,qs,qe,2*segIdx+2);
    node temp;
    int x = min(temp1.unusedOpen,temp2.unusedClosed);
    temp.pairs = temp1.pairs + temp2.pairs + x;
    temp.unusedOpen = temp1.unusedOpen + temp2.unusedOpen - x;
    temp.unusedClosed = temp1.unusedClosed + temp2.unusedClosed - x;
    return temp;
}
int main() {
    int t;
    cin>>t;
    for(int cs=0; cs<t; cs++) {
        string str;
        int q=1;
        cin>>str>>q;
        int l,r;
        int n = str.length();
        int size = 2*(pow(2,(ceil(log(n)/log(2)))))-1;
        struct node tree[size];
        // for(int i=0; i<size; i++) tree.push_back(new node(0,0,0));
        // struct node *tree = new struct node[size];
        makeTree(str,tree,0,n-1,0);
        // for(int i=0; i<size; i++) cout<<tree[i].pairs<<" ";
        // cout<<endl;
        for(int i=0; i<q; i++) {
            cin>>l>>r;
            cout<<(query(tree,0,n-1,l,r,0).pairs*2)<<endl;
        }
    }
}
