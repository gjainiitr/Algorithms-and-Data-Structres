// Problem URL :- https://practice.geeksforgeeks.org/problems/print-distinct-elements-1587115620/1

#include <bits/stdc++.h>
using namespace std;

void printNonRepeated(int arr[],int n);


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
	    
	    printNonRepeated(arr,n);
	    
	    cout<<endl;
	    
	}
	return 0;
}// } Driver Code Ends

// Function to print the non repeated elements in the array
// arr[]: input array
// n: size of array
void printNonRepeated(int arr[],int n)
{
    //Your code here
    unordered_map<int,int> mp;
    int count = 0;
    for(int i=0; i<n; i++) {
        mp[arr[i]]++;
    }
    for(int j=0; j<n; j++) {
        if(mp[arr[j]] == 1) cout<<arr[j]<<' ';
    }

}
