// Problem URL :- https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1

// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// This function wants you to modify the given input
// array and no need to return anything
// arr: input array
// n: size of array
void rearrange(int *arr, int n) 
{ 
	// Your code here
    int max=0,min=1;
    int k=1+arr[n-1];
    
    int j = n-1;
    while(max<n) {
        arr[max] = arr[max]%k + k*(arr[j]%k);
        j--;
        max+=2;
    }
    j = 0;
    while(min<n) {
        arr[min] = arr[min]%k + k*(arr[j]%k);
        j++;
        min+=2;
    }
    for(int i=0; i<n; i++) arr[i]/=k;
}

// { Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        rearrange(arr, n);
        
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 
  // } Driver Code Ends
