// Problem URL :- https://practice.geeksforgeeks.org/problems/wave-array-1587115621/1

#include<bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
// Function to convert given array to wave like array
// arr: input array
// n: size of array
int min(int a, int b) {
    if(a>b) return b;
    return a;
}
void convertToWave(int *arr, int n){
    int temp,start,end;
    // Your code here
    for(int i=0; i<n; i+=2) {
        start = i; end = min(i+1,n-1);
        temp=arr[start];
        arr[start]= arr[end];
        arr[end] = temp;
    }
}

int main()
{
    int t,n;
    cin>>t; //Input testcases
    while(t--) //While testcases exist
    {
        cin>>n; //input size of array
        int a[n]; //declare array of size n
        for(int i=0;i<n;i++)
            cin>>a[i]; //input elements of array
        
        convertToWave(a, n);

        for(int i=0;i<n;i++)
            cout<<a[i]<<" "; //print array
            
        cout<<endl;
    }
}
