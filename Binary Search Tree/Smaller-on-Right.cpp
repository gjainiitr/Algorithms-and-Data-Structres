/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/smaller-on-right/0
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    int smaller;
    node *left, *right;
    node(int value=0) {
        data = value;
        smaller = 0;
        left = NULL;
        right = NULL;
    }
};
int max(int a, int b) {
    if(a>b) return a;
    return b;
}
bool insertBST(node* &root, int &ans,int k) {
    // if(s.find(k)!=s.end()) return;
    if(root==NULL) {
        root = new node(k);
        return 1;
    }
    if(root->data == k) {
        ans += root->smaller;
        return 0;
    }
    if(k < root->data) {
        root->smaller = root->smaller + 1;
        if(insertBST(root->left,ans,k)==false) {
            root->smaller = root->smaller - 1;
            return false;
        } else {
            return true;
        }
    }
    if(k > root->data) {
        ans += root->smaller + 1;
        return insertBST(root->right,ans,k);
    }
}
void printBST(node *root) {
    if(root==NULL) return;
    printBST(root->left);
    cout<<root->smaller<<" ";
    printBST(root->right);
}
int findSmaller(node* root, int k) {
    if(root==NULL) return 0;
    if(root->data == k) {
        return root->smaller;
    }
    if(k<root->data) {
        return findSmaller(root->left,k);
    }
    if(k>root->data) {
        return (1+(root->smaller)+findSmaller(root->right,k));
    }
}
int smallerOnRight(int arr[], int n) {
    // unordered_set<int> s; // stores data about no. of nodes on left of a node
    // for(int i=0; i<n; i++) s.insert(arr[i]);
    struct node* root=NULL;
    int res=0,temp=0;
    insertBST(root,temp,arr[n-1]);
    // s.insert(arr[n-1]);
    for(int i=n-2; i>=0; i--) {
        temp=0;
        insertBST(root,temp,arr[i]); // insert it first - O(log n)
        // s.insert(arr[i]);
        // now find no. of smaller elements for arr[i]
        res = max(res, temp);
    }
    return res;
    // cout<<"\n##################################\n";
    // printBST(root);
    // cout<<"\n##################################\n";
}
int main() {
    int t;
    cin>>t;
    for(int cs=0; cs<t; cs++) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        cout<<smallerOnRight(arr,n)<<endl;
    }
}
