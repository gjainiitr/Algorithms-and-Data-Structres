// Problem URL :- https://practice.geeksforgeeks.org/problems/peak-element/1

#include<bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
/* The function should return the index of any
   peak element present in the array */
// arr: input array
// n: size of array
int peakElement(int arr[], int n)
{
   // Your code here
   int mid, low=0, high = n-1;
   while(high >= low) {
       mid = high - (high - low)/2;
       if( ( mid==0 || (arr[mid] > arr[mid-1]) )  && ( mid==(n-1) || (arr[mid]>arr[mid+1]) ) ) return mid;
       else if (arr[mid-1] > arr[mid]) high = mid - 1;
       else low = mid + 1;
   }
   return -1;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		bool f=0;
		int A = peakElement(a,n);
		
		if(n==1)
		f=1;
		else
		if(A==0 and a[0]>=a[1])
		f=1;
		else if(A==n-1 and a[n-1]>=a[n-2])
		f=1;
		else if(a[A] >=a[A+1] and a[A]>= a[A-1])
		f=1;
		else
		f=0;
		
		cout<<f<<endl;
		
	}

	return 0;
}
