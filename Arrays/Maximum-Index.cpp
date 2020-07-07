// Problem URL :- https://practice.geeksforgeeks.org/problems/maximum-index-1587115620/1

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to find the maximum difference of j-i
// arr[]: input array
// n: size of array
int max(int a, int b) {
    if(a>b) return a;
    return b;
}
int maxIndexDiff(int arr[], int n) 
{ 
    
    // Your code here
    int i,j,res=0;
    for(int j=n-1; j>=0; j--) {
        i=0;
        while(i<=j) {
            if(arr[i]<=arr[j]) {
                res = max(res,j-i);
                break;
            }
            i++;
        }
    }
    return res;
}

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    cin>>T;
    while(T--){
        int num;
        cin>>num;
        int arr[num];
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        
        if(num ==1 ){
            cout<<0<<endl;
            continue;
        }
        cout<<maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends
