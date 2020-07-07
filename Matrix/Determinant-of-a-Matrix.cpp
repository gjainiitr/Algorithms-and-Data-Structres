// Problem URL :- https://practice.geeksforgeeks.org/problems/determinant-of-a-matrix-1587115620/1

// C++ program to find Deteminant of a matrix
#include <bits/stdc++.h>
using namespace std;

// Dimension of input square matrix
#define N 100


 // } Driver Code Ends
/*  Function to find determinant of matrix
*   mat[][]: input matrix
*   n: given size of matrix
*   N: defined size globally
*/
void getCofactor(int mat[N][N], int temp[N][N], int p, int q, int n) {
    int i=0, j=0;
    for(int row=0; row<n; row++) {
        for(int col=0; col<n; col++) {
            if(row!=p && col!=q) {
                temp[i][j] = mat[row][col];
                j++;
                if(j==n-1) {
                    i++;
                    j=0;
                }
            }
        }
    }
}
int determinantOfMatrix( int mat[N][N], int n)
{
    
    // Your code here
    int temp[N][N];
    int det=0, sign = 1;
    if(n==1) return mat[0][0];
    for(int f=0; f<n; f++) {
        getCofactor(mat,temp,0,f,n);
        det+= sign*mat[0][f]*determinantOfMatrix(temp,n-1);
        sign *= -1;
    }
    return det;
    
}

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
	  int t;
	cin>>t;
	while(t--)
	{
	  int no;
	cin>>no;
	  int mat[N][N];
	for(  int i=0;i<no;i++)
	{
	    for(  int j=0;j<no;j++)
	    {
	        cin>>mat[i][j];
	    }
	}
	printf("%d",determinantOfMatrix(mat, no));
	printf("\n");
	}
	return 0;
}  // } Driver Code Ends
