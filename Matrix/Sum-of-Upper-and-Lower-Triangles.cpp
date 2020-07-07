// Problem URL :- https://practice.geeksforgeeks.org/problems/sum-of-upper-and-lower-triangles-1587115621/1

#include <bits/stdc++.h>
using namespace std;

#define SIZE 100


 // } Driver Code Ends
/*  Function to find sum of upper and lower triangles

*   n: row/col in matrix
*   mat[][]: input matrix
*/
void sumTriangles(int n, int mat[SIZE][SIZE]){
int sumU=0,sumL=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<=i; j++) {
          sumL += mat[i][j];
          sumU += mat[n-1-i][n-1-j];
        }
    cout<<sumU<<" "<<sumL;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t; //input the testcases
    while(t--) //while testcases exist
    {
        long int r,n,c,us=0,ls=0;
        cin>>n; //input number of rows 
        r=n;
        c=r; //Since the matrix is a square matrix, number of cols=number of rows
        int i,j,mat[SIZE][SIZE];
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            cin>>mat[i][j]; //input the elements of matrix
        }
        
        sumTriangles(r, mat);
        
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
