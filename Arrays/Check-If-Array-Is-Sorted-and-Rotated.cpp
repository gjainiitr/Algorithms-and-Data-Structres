// Problem URL :- https://practice.geeksforgeeks.org/problems/check-if-array-is-sorted-and-rotated-clockwise-1587115620/1

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// arr: input array
// num: length of array
// This function returns true or false
int max(int a, int b) {
    if(a>b) return a;
    return b;
}
bool checkRotatedAndSorted(int arr[], int num){
    
    // Your code here
    int ncMax=0, pcMax=0, nc=0,pc=0;
    for(int i=0; i<(2*num)-1; i++) {
        if((arr[i%num])<(arr[(i+1)%num])) {
            pc++;
            ncMax = max(ncMax,nc);
            nc=0;
        } else {
            nc++;
            pcMax = max(pcMax,pc);
            pc=0;
        }
    }
    if(pcMax==(num-1) && arr[0]>arr[num-1]) return true;
    if(ncMax==(num-1) && arr[0]<arr[num-1]) return true;
    return false;
}

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--){
	    int num;
        cin>>num;
        int arr[num];
        for(int i = 0; i<num; ++i)
            cin>>arr[i];
        
        bool flag = false;
        
        flag = checkRotatedAndSorted(arr, num);
        
        if(!flag){
            cout << "No"<<endl;
        }
        else
        cout << "Yes"<<endl;
    
	}
	
	return 0;
}  // } Driver Code Ends
