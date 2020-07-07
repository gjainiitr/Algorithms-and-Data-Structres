// Problem URL :-https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
int findPlatform(int arr[], int dep[], int n)
{
	// Your code here
	sort(arr,arr+n);
	sort(dep,dep+n);
    int i=1, j=0, pfCurr=1, pfMax=1;
    while(i<n) {
        while(dep[j]<arr[i]) {
            pfCurr--;
            j++;
        }
        if(dep[j]>=arr[i]) {
            pfCurr++;
            pfMax = pfMax>pfCurr?pfMax:pfCurr;
        }
        i++;
    }
    return pfMax;
}

// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
           for(int i=0;i<n;i++)
        cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
    cout <<findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends
