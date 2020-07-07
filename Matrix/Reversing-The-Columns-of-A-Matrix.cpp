// Problem URL :- https://practice.geeksforgeeks.org/problems/reversing-the-columns-of-a-matrix-1587115621/1

#include <bits/stdc++.h>
using namespace std;

#define SIZE 50

void reverseCol(int n1, int m1, int arr1[SIZE][SIZE]);

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int n1,m1;
        cin>>n1>>m1;
        int arr1[SIZE][SIZE];
        for(int i=0;i<n1;i++)
        for(int j=0;j<m1;j++)
        cin>>arr1[i][j];
        
        reverseCol(n1, m1, arr1);
        
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<m1;j++)
            cout<<arr1[i][j]<<" ";
        }
        
        cout<<endl;
    }
    
	return 0;
}// } Driver Code Ends
//Complete this function
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void reverseCol(int n1, int m1, int arr1[SIZE][SIZE])
{
    //Your code here
        
    // Your code here
    // change first and last column
    for(int i=0; i<n1; i++) {
        for(int j=0; j<m1/2; j++) {
            swap(arr1[i][j],arr1[i][m1-1-j]);
        }
    }
    
    // for(int i=0; i<n1; i++) {
    //     for(int j=0; j<m1; j++) {
    //         cout<<arr1[i][j]<<' ';
    //     }
    //     // cout<<endl;
    // }
}


