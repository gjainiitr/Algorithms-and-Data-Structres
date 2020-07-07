/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/minimum-swaps/1
*/
// { Driver Code Starts
// C++ program to find minimum number of swaps
// required to sort an array
#include<bits/stdc++.h>
using namespace std;

int minSwaps(int A[], int N);

// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}

// } Driver Code Ends


/* You are required to complete this method */
int minSwaps(int arr[], int n){
    /*Your code here */
    int res=0;
    int minimum;
    int i,j;
    int temp;
    int minIdx;
    for(i=0; i<n-1; i++) {
        minimum = arr[i];
        minIdx = i;
        for(j=i+1; j<n; j++) {
            // minimum = min(minimum, arr[j]);
            if(minimum > arr[j]) {
                minimum = arr[j];
                minIdx = j;
            }
        }
        if(minIdx == i) continue;
        // if(i<j)  {
            res+=1;
            swap(arr[i],arr[minIdx]);
        
        // temp = arr[i];
        // arr[i] = arr[j];
        // arr[j] = temp;
    }
    return res;
}

