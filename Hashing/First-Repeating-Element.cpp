// Problem URL :- https://practice.geeksforgeeks.org/problems/first-repeating-element/0

#include <bits/stdc++.h>
using namespace std;

void firstRepeating(int arr[],int n);


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
	    
	    firstRepeating(arr,n);
	    
	    cout<<endl;
	    
	}
	return 0;
}// } Driver Code Ends

// Function to print the non repeated elements in the array
// arr[]: input array
// n: size of array
void firstRepeating(int arr[],int n)
{
    //Your code here
    bool found = false;
    unordered_map<int,int> mp;
    int count = 0;
    for(int i=0; i<n; i++) {
        mp[arr[i]]++;
    }
    for(int i=0; i<n; i++) {
        if(mp[arr[i]]>=2) {
            found=true;
            cout<<i+1;
            break;
        }
    }
    if(!found) cout<<-1;
}
