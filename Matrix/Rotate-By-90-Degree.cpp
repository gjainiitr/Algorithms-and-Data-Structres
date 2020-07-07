// Problem URL :- https://practice.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1

#include<bits/stdc++.h>
using namespace std;
#define N 50


 // } Driver Code Ends
/*  Function to rotate matrix by 90 degrees
*   n: input for matrix size
*   N: size defined globally
*/
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void rotateby90(int n, int a[][N]){
    
    // Your code here
    for(int i=0; i<n; i++) {
	    for(int j=0; j<i; j++)
	        swap(a[i][j],a[j][i]);
	}
	for(int i=0; i<n/2; i++)
	    for(int j=0; j<n; j++)
	        swap(a[i][j],a[n-1-i][j]);
}

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t; //inputting testcases
	while(t--)
	{
		int n;
		cin>>n; //inputing n for square matrix
		int a[N][N],i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>a[i][j]; //Inputting the matrix
			}
		}
		
		rotateby90(n, a);
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout<<a[i][j]<<" "; //printing the resultant matrix
			}
		}
		cout<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends
