// Problem URL :- https://practice.geeksforgeeks.org/problems/closer-to-sort-1587115620/1

#include <iostream>
using namespace std;


 // } Driver Code Ends
// Function to find the index of x
// arr[]: input array
// n: size of array
// x: element to find index
bool firstOccur(int arr[], int mid, int x) {
    if(mid==0) return true;
    if(arr[mid-1]!=x) return true;
    return false;
}
int closer(int arr[],int n, int x)
{
    //Your code here
    int l=0,h=n-1,mid;
    while(l<=h) {
        mid = l + (h-l)/2;
        if(arr[mid]==x && firstOccur(arr,mid,x)) return mid;
        else if(mid!=(n-1) && arr[mid+1]==x && firstOccur(arr,mid+1,x)) return mid+1;
        else if(mid!=0 && arr[mid-1]==x && firstOccur(arr,mid-1,x)) return mid-1;
        else if(arr[mid]>=x) h=mid-1;
        else l=mid+1;
    }
    return -1;
}

// { Driver Code Starts.

int main() {
    
    cin.tie(NULL);
    
	int t;
	cin >> t;
	
	while(t--){
	  
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    int x;
	    cin >> x;
	    
	    int res = closer(arr,n,x);
	    
	    cout << res << endl;
	}
	
	return 0;
}  // } Driver Code Ends
