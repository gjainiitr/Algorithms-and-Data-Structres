// Problem URL :- https://practice.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1

#include <bits/stdc++.h>
using namespace std;

long long arr[10000000];


 // } Driver Code Ends


long long findNumberOfTriangles(long long n)
{
    //Your code here
    // 10 9 8 7 6 5 4 3 2 1
    // 0 1 2 3 4 5 6 7 8 9 10
    // arr[], n
    long long count = 0,temp,sum;
    sort(arr, arr+n);
    int i,low,high;
    for(i=n-1; i>1; i--) {
        low = 0; high = i-1;
        while(low<high) {
            if(arr[low]+arr[high]>arr[i]) {
                count+=high-low;
                high--;
            } else {
                low++;
            }
        }
    }
    return count;
}

// { Driver Code Starts.

int main()
{
    long long size,T;
    
    cin>>T;

    while(T--){
        
    cin>>size;

    for(int i=0;i<size;i++)
     cin>>arr[i];
     
    cout<<findNumberOfTriangles(size ) <<endl;
    }
    return 0;
}


  // } Driver Code Ends
