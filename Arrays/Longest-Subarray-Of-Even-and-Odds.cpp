// Problem URL :- https://practice.geeksforgeeks.org/problems/longest-subarray-of-evens-and-odds/1


//Initial Template for C++


#include<iostream> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++
bool bothSameOddity(int a, int b) {
    if(a%2==0 && b%2==0) return true;
    if(a%2!=0 && b%2!=0) return true;
    return false;
}
int max(int a, int b) {
    if(a>b) return a;
    return b;
}
//Complete this function
int maxEvenOdd(int arr[], int n) 
{ 
   //Your code here
   int size=1,res=1;
   for(int i=1; i<n; i++) {
       if(bothSameOddity(arr[i],arr[i-1])) {
           res = max(res, size);
           size=1;
       } else {
           size++;
       }
   }
   res = max(res, size);
   return res;
} 

// { Driver Code Starts.



/* Driver program to test maxSubArraySum */
int main() 
{ 
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        
        for(int i=0;i<sizeOfArray;i++)
        {
            cin>>arr[i];
        }
        cout  << maxEvenOdd(arr, sizeOfArray)<<endl; 
    }
   return 0; 
} 
  // } Driver Code Ends
