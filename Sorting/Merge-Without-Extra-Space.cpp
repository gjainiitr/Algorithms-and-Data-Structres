// Problem URL :- https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
// Function to merge two input arrays
// arr1[], arr2[]: input arrays
// n, m: size of arr1[] and arr2[] respectively
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
int max(int a, int b) {
	if(a>b) return a;
	return b;
}
void merge(int arr1[], int arr2[], int n, int m) 
{
	int i=n-1, j=0;
    while(i>=0) {
        if(j==m) break;
        if(arr1[i]<=arr2[j]) break;
        else {
            swap(arr1[i],arr2[j]);
            j++; i--;
        }
    }
	sort(arr1, arr1+n);
	sort(arr2, arr2+m);
} 

// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    int arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    
	    merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            printf("%d ", arr1[i]); 
        
       
	    for (int i = 0; i < m; i++) 
		    printf("%d ", arr2[i]); 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends
