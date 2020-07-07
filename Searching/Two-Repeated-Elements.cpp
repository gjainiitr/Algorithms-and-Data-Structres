// Problem URL :- https://practice.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to find the two repeated element
// arr: input array
// n: size of array
void twoRepeated(int arr[], int n){
    int num1=0, num2=0;
    // Your code here
    int arr2[n+1]={0};
    for(int i=0; i<n+2; i++)
        arr2[arr[i]]++;
    for(int i=1; i<=n; i++) {
        if(arr2[i]==2) {
            if(num1==0) num1=i;
            else num2=i;
        } 
    }
    for(int i=0; i<n+2; i++) {
        if(arr[i]==num1 && --arr2[num1]==0) {
            cout<<num1<<" "<<num2;
            arr2[num1]--;
            break;
        }
        if(arr[i]==num2 && --arr2[num2]==0) {
            cout<<num2<<" "<<num1;
            arr2[num2]--;
            break;
        }
    }
    
}

// { Driver Code Starts.

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int a[n+2];
        
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        
        twoRepeated(a, n);
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends
