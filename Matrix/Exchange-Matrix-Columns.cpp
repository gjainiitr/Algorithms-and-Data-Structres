// Problem URL :- https://practice.geeksforgeeks.org/problems/exchange-matrix-columns-1587115620/1

#include <bits/stdc++.h>
using namespace std;

#define SIZE 100


 // } Driver Code Ends
/*  Function to exchange columns
*   n1, m1: rows and cols of matrix
*   SIZE: defined globally for matrix
*   arr1[][]: input matrix
*/
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void exchangeColumns(int n1, int m1, int arr1[SIZE][SIZE]){
    
    // Your code here
    // change first and last column
    for(int i=0; i<n1; i++) swap(arr1[i][0],arr1[i][m1-1]);
    
    for(int i=0; i<n1; i++) {
        for(int j=0; j<m1; j++) {
            cout<<arr1[i][j]<<' ';
        }
        // cout<<endl;
    }
    
}

// { Driver Code Starts.

int main() {
    long long t;
    cin>>t;
    while(t--)
    {
        int n1,m1;
        cin>>n1>>m1;
        int arr1[SIZE][SIZE];
        for(int i=0;i<n1;i++)
        for(int j=0;j<m1;j++)
        cin>>arr1[i][j];
        
        exchangeColumns(n1, m1, arr1);
        cout<<endl;
    }
    
	return 0;
}  // } Driver Code Ends
