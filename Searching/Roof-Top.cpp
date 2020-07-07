// Problem URL :- https://practice.geeksforgeeks.org/problems/roof-top-1587115621/1

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
int maxStep(int a[], int n){
     int moxxi=0, count=0;
    for(int i=1;i<n;i++){
        if (a[i]>a[i-1]){
            count++;
        }
        if (a[i]<=a[i-1] || a[i]==a[n-1]){
            if (count>moxxi)
                moxxi=count;
            count=0;
        }
    }
    return moxxi;
}
// { Driver Code Starts.


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    
	    cout << maxStep(a, n) << endl;
	}
	return 0;
}  // } Driver Code Ends
