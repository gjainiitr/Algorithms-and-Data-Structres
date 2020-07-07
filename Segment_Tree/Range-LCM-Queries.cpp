/*
 Problem URL :- https://practice.geeksforgeeks.org/problems/range-lcm-queries/0
*/
#include<bits/stdc++.h>
using namespace std; 
  
#define MAX 1000 
  
// allocate space for tree 
// int tree[4*MAX]; 
  
// declaring the array globally 
// int arr[MAX]; 
  
// Function to return gcd of a and b 
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
} 
  
//utility function to find lcm 
int lcm(int a, int b) 
{ 
    return a*b/gcd(a,b); 
} 
  
// Function to build the segment tree 
// Node starts beginning index of current subtree. 
// start and end are indexes in arr[] which is global 
void build(int tree[], int arr[], int node, int start, int end) 
{ 
    // If there is only one element in current subarray 
    if (start==end) 
    { 
        tree[node] = arr[start]; 
        return; 
    } 
  
    int mid = (start+end)/2; 
  
    // build left and right segments 
    build(tree,arr,2*node, start, mid); 
    build(tree,arr,2*node+1, mid+1, end); 
  
    // build the parent 
    int left_lcm = tree[2*node]; 
    int right_lcm = tree[2*node+1]; 
  
    tree[node] = lcm(left_lcm, right_lcm); 
} 
  
// Function to make queries for array range )l, r). 
// Node is index of root of current segment in segment 
// tree (Note that indexes in segment tree begin with 1 
// for simplicity). 
// start and end are indexes of subarray covered by root 
// of current segment. 
int query(int tree[], int node, int start, int end, int l, int r) 
{ 
    // Completely outside the segment, returning 
    // 1 will not affect the lcm; 
    if (end<l || start>r) 
        return 1; 
  
    // completely inside the segment 
    if (l<=start && r>=end) 
        return tree[node]; 
  
    // partially inside 
    int mid = (start+end)/2; 
    int left_lcm = query(tree,2*node, start, mid, l, r); 
    int right_lcm = query(tree,2*node+1, mid+1, end, l, r); 
    return lcm(left_lcm, right_lcm); 
} 
void update(int tree[],int index,int s,int e,int pos,int val)
{
	if(pos<s || pos>e)
		return ;
	if(s==e)
	{
		tree[index] = val;
		return ;
	}
	int m = (s+e)/2;
	update(tree,2*index,s,m,pos,val);
	update(tree,2*index+1,m+1,e,pos,val);
	tree[index]= (tree[2*index]*tree[2*index+1])/gcd(tree[2*index],tree[2*index+1]);
	return;
}
  
//driver function to check the above program 
int main() 
{ 

    int t;
    cin>>t;
    for(int cs=0; cs<t; cs++) {
        int n,q;
        cin>>n>>q;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        int tree[4*n] = {0};
        build(tree,arr,1,0,n-1);
        // char identifier;
        // int first,second;
        char type;
        int first,second;
        for(int i=0; i<q; i++) {
            cin>>type;
            cin>>first>>second;
            if(type=='G') {
                cout<<query(tree,1,0,n-1,first,second)<<endl;
            } else if(type=='U') {
                arr[first] = second;
                update(tree,1,0,n-1,first,second);
            }
        }
    }
  

  
    return 0; 
} 
