// Problem URL :- https://practice.geeksforgeeks.org/problems/sort-by-absolute-difference-1587115621/1

// {
#include<bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
// Function to sort the given array according to
// the difference with K
// A[]: input array
// N: size of array
int mod(int a) {
    if(a>0) return a;
    return -1*a;
}
bool myComparator(int a,int b) {
    if(mod(a)<mod(b)) return true;
    return false;
}
void sortABS(int A[],int N,int k)
{
   //Your code here
     for(int i=0; i<N; i++) A[i]-=k;
     stable_sort(A,A+N,myComparator);
     
     for(int i=0; i<N; i++) A[i]+=k;
   
}


// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    
	    int N, diff;
	    cin>>N>>diff;
	    int A[N];
	    
	    for(int i = 0; i<N; i++)
	        cin>>A[i];
	   
	    sortABS(A, N, diff);
	    
	    for(int & val : A)
	        cout<<val<<" ";
	    cout<<endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
