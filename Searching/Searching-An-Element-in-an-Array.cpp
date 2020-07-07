// Problem URL :- https://practice.geeksforgeeks.org/problems/search-an-element-in-an-array-1587115621/1

#include<bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
// Function to search x in arr
// arr: input array
// x: element to be searched for
int search(int arr[], int n, int x)
{
    
    // Your code here
    for(int i=0; i<n; i++) {
        if(arr[i]==x) return i;
    }
    return -1;
    
}


int main()
{
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        int x;
        
        for(int i=0;i<sizeOfArray;i++)
        {
            cin>>arr[i];
        }
        cin>>x;
        cout<<search(arr,sizeOfArray,x)<<endl; //Linear search
    }

    return 0;
    
}

