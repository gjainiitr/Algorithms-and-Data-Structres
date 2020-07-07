/*
 Problem URL :- https://practice.geeksforgeeks.org/problems/largest-sum-contiguous-subarray-in-range-1587115620/1
*/

//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Structure of node of the tree
struct node {
	int sum, prefixsum, suffixsum, maxsum;
};

// A Max of 1000 Node Array
node tree[4 * 1000];

// Utility funciton to build the tree
void build(int arr[], int low, int high, int index)
{
	if (low == high) {
		tree[index].sum = arr[low];
		tree[index].prefixsum = arr[low];
		tree[index].suffixsum = arr[low];
		tree[index].maxsum = arr[low];
	} else {
		int mid = (low + high) / 2;
		build(arr, low, mid, 2 * index + 1);
		build(arr, mid + 1, high, 2 * index + 2);
		tree[index].sum = tree[2 * index + 1].sum + tree[2 * index + 2].sum;
		tree[index].prefixsum = max(tree[2 * index + 1].prefixsum, tree[2 * index + 1].sum + tree[2 * index + 2].prefixsum);
		tree[index].suffixsum = max(tree[2 * index + 2].suffixsum, tree[2 * index + 2].sum + tree[2 * index + 1].suffixsum);
		tree[index].maxsum = max(tree[index].prefixsum, max(tree[index].suffixsum, max(tree[2 * index + 1].maxsum, max(tree[2 * index + 2].maxsum,tree[2 * index + 1].suffixsum + tree[2 * index + 2].prefixsum))));
	}
}

// Your task is to complete this function
// function should update the array and as Tree as well accordingly
void update(int arr[], int arrSize, int index, int value);

// Your task is to complete this function
// funciton should return the Max-Sum in the range
int query(int arr[], int arrSize, int l, int r);

// Driver Code
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
	    int n, q, index, value, left, right, type;
	    int* arr = NULL;
	    cin>>n>>q;
	    arr = new int[n];
	    for(int i=0; i<n; i++)cin>>arr[i];
	    build(arr, 0, n-1, 0);
	    for(int i=0; i<q; i++){
	        cin>>type;
	        if(type==1){
	            cin>>left>>right;
	            cout<<query(arr, n, left, right)<<endl;
	        } else {
	            cin>>index>>value;
	            update(arr, n, index, value);
	        }
	    }
	    delete [] arr;
	    arr = NULL;
	}
	return 0;
}

 // } Driver Code Ends

//User function Template for C++
// Your task is to complete this function
// function should update the array and Tree as well accordingly
void makeUpdate(int arr[], int index, int low, int high,  
            int idx, int value) 
{ 
    // the node to be updated 
    if (low == high) { 
        tree[index].sum = value; 
        tree[index].prefixsum = value; 
        tree[index].suffixsum = value; 
        tree[index].maxsum = value; 
    } 
    else { 
  
        int mid = (low + high) / 2; 
  
        // if node to be updated is in left subtree 
        if (idx <= mid) 
            makeUpdate(arr, 2 * index + 1, low, mid, idx, value); 
          
        // if node to be updated is in right subtree 
        else
            makeUpdate(arr, 2 * index + 2, mid + 1,  
                   high, idx, value); 
  
        // parent node's sum is the summation of left  
        // and right child 
        tree[index].sum = tree[2 * index + 1].sum +  
                          tree[2 * index + 2].sum; 
  
        // parent node's prefix sum will be equivalent 
        // to maximum of left child's prefix sum or left  
        // child sum + right child prefix sum. 
        tree[index].prefixsum =  
                    max(tree[2 * index + 1].prefixsum, 
                    tree[2 * index + 1].sum +  
                    tree[2 * index + 2].prefixsum); 
  
        // parent node's suffix sum will be equal to right 
        // child suffix sum or right child sum + suffix  
        // sum of left child 
        tree[index].suffixsum =  
                    max(tree[2 * index + 2].suffixsum, 
                    tree[2 * index + 2].sum +  
                    tree[2 * index + 1].suffixsum); 
  
        // maxum will be the maximum of prefix, suffix of 
        // parent or maximum of left child or right child 
        // and summation of left child's suffix and  
        // right child's prefix. 
        tree[index].maxsum =  
                    max(tree[index].prefixsum, 
                    max(tree[index].suffixsum, 
                    max(tree[2 * index + 1].maxsum, 
                    max(tree[2 * index + 2].maxsum, 
                    tree[2 * index + 1].suffixsum +  
                    tree[2 * index + 2].prefixsum)))); 
    } 
} 
  
// fucntion to return answer to  every type-1 query 

void update(int arr[], int arrSize, int index, int value) {
    // code here
//    void makeUpdate(int arr[], int index, int low, int high,  
//            int idx, int value)
    arr[index-1]=value;
    makeUpdate(arr,0,0,arrSize-1,index-1,value);
}


node makeQuery(int arr[], int index, int low,  
           int high, int l, int r) 
{ 
    // initially all the values are INT_MIN 
    node result; 
    result.sum = result.prefixsum =  
                 result.suffixsum =  
                 result.maxsum = INT_MIN; 
  
    // range does not lies in this subtree 
    if (r < low || high < l) 
        return result; 
  
    // complete overlap of range 
    if (l <= low && high <= r) 
        return tree[index]; 
  
    int mid = (low + high) / 2; 
  
    // right subtree 
    if (l > mid) 
        return makeQuery(arr, 2 * index + 2,  
                     mid + 1, high, l, r); 
          
    // left subtree     
    if (r <= mid) 
        return makeQuery(arr, 2 * index + 1,  
                     low, mid, l, r); 
  
    node left = makeQuery(arr, 2 * index + 1,  
                      low, mid, l, r); 
    node right = makeQuery(arr, 2 * index + 2,  
                        mid + 1, high, l, r); 
  
    // finding the maximum and returning it 
    result.sum = left.sum + right.sum; 
    result.prefixsum = max(left.prefixsum, left.sum +  
                           right.prefixsum); 
                             
    result.suffixsum = max(right.suffixsum, 
                       right.sum + left.suffixsum); 
    result.maxsum = max(result.prefixsum, 
                    max(result.suffixsum, 
                    max(left.maxsum, 
                    max(right.maxsum, 
                    left.suffixsum + right.prefixsum)))); 
                      
    return result; 
} 
int query(int arr[], int n, int l, int r) { // tree is accessible globally
    // code here
//    node makeQuery(int arr[], int index, int low,  
//           int high, int l, int r)
    return (makeQuery(arr,0,0,n-1,l-1,r-1).maxsum);
}

// { Driver Code Starts.  // } Driver Code Ends
