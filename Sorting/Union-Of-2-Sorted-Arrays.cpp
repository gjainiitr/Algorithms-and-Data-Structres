// Problem URL :- https://practice.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//arr1,arr2 : the arrays
// n, m: size of arrays
void findUnion(int arr1[], int arr2[], int n, int m)
{
    int i=0,j=0;
    while(i<n && j<m) {
        if(i!=0 && arr1[i]==arr1[i-1]) {
            i++; continue;
        }
        if(j!=0 && arr2[j]==arr2[j-1]) {
            j++; continue;
        }
        if(arr1[i]<arr2[j]) {
            cout<<arr1[i]<<' '; i++; 
        } else if (arr1[i]>arr2[j]) {
            cout<<arr2[j]<<' '; j++;
        } else {
            cout<<arr1[i]<<' '; i++; j++;
        }
    }
    while(i<n) {
        if(i==0 || arr1[i]!=arr1[i-1]) {
        	cout<<arr1[i]<<' '; i++;
        } else i++;

    }
    while(j<m) {
        if(j==0 || arr2[j]!=arr2[j-1]) {
	        cout<<arr2[j]<<' '; j++;
        } else j++;

    }
}

// { Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    
	    findUnion(arr1,arr2, N, M);
	    
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
