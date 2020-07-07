// Problem URL :- https://practice.geeksforgeeks.org/problems/count-distinct-elements-1587115620/1

#include <bits/stdc++.h>
using namespace std;

int countNonRepeated(int arr[], int n);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	    cout<<countNonRepeated(arr,n)<<endl;
	    
	}
	return 0;
}
// } Driver Code Ends
//Complete this function

int countNonRepeated(int arr[], int n)
{
        //Your code here
    unordered_map<int,int> mp;
    int count = 0;
    for(int i=0; i<n; i++) {
        mp[arr[i]]++;
    }
    for(int j=0; j<n; j++) {
        if(mp[arr[j]] == 1) count++;
    }
    return count;
}

