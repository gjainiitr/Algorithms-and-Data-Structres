// Problem URL :- https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1



#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// function to find the triplet which sum to x
bool find3Numbers(int A[], int arr_size, int x)
{
    //Your code here
        int sum;
    //Your code here
    sort(A, A+arr_size);
    for(int i=0; i<arr_size-2; i++) {
        int j=i+1, k=arr_size-1;
        while(j<k) {
            sum = A[i]+A[j]+A[k];
            if(sum==x) return true;
            else if (sum>x) k--;
            else j++;
        } 
    }
    return false;
}


// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,sum;
		cin>>N>>sum;
		int i,A[N];
		for(i=0;i<N;i++)
			cin>>A[i];
        cout <<  find3Numbers(A, N, sum) << endl;
    }
}
  // } Driver Code Ends
