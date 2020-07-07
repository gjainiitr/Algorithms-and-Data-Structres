// Problem URL :- https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to find circular subarray with maximum sum
// arr: input array
// num: size of array
int max(int a, int b) {
    if(a>b) return a;
    return b;
}
int circularSubarraySum(int arr[], int num){
    

    int res=INT_MIN, sum=0,a,b;
    // Kadane of arr
    for(int i=0; i<num; i++) {
        if(sum<0) sum=0;
        sum+=arr[i];
        res=max(res,sum);
    }
    a = res; res=INT_MIN; sum=0;

    // Counting Total sum
    int totalSum=0;
    for(int i=0; i<num; i++) totalSum+=arr[i];
    
    // Reverse kadane
    for(int i=0; i<num; i++) arr[i]*=-1;
    for(int i=0; i<num; i++) {
        if(sum<0) sum=0;
        sum+=arr[i];
        res=max(res,sum);
    }
    b = totalSum+res;
    if(b==0) return a;
    else return max(a,b);
}

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num;
	    cin>>num;
	    int arr[num];
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	    
	    
	    cout << circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
