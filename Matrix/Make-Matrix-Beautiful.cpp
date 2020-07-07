// Problem URL :- https://practice.geeksforgeeks.org/problems/make-matrix-beautiful-1587115620/1

#include <bits/stdc++.h>
using namespace std;

int findMinOpeartion(int matrix[][100], int n);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mat[n][100];
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>mat[i][j];
        cout << findMinOpeartion(mat, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
//Complete this function
int max(int a, int b) {
    if(a>b) return a;
    return b;
}
// Function to find minimum number of operation
int findMinOpeartion(int matrix[][100], int n)
{
    //Your code here
    int maxSum=0, totalSum=0;
    int temp=0;
    for(int i=0; i<n; i++) {
        temp=0;
        for(int j=0; j<n; j++) {
            temp+=matrix[i][j];
        }
        totalSum+=temp;
        maxSum = max(maxSum,temp);
    }
    for(int j=0; j<n; j++) {
        temp=0;
        for(int i=0; i<n; i++) {
            temp+=matrix[i][j];
        }
        maxSum=max(temp,maxSum);
    }
    return (n*maxSum)-totalSum;
}


