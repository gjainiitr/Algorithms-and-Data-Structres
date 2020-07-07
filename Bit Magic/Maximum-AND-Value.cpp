// Problem URL :- https://practice.geeksforgeeks.org/problems/maximum-and-value-1587115620/1

#include<bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
int max(int a, int b) {
    if(a>b) return a;
    return b;
}
// Function for finding maximum and value pair
int maxAND (int arr[], int n)
{   
   // Your code here
   int pattern=0,temp=0, result,max_num=0,max_digits=0,temp_pattern=0,counter=0;
   
// Step-1 : Find the largest no.
   for(int i=0; i<n; i++) {
       max_num = max(arr[i], max_num);
   }
// Step-2 : Find no. of digits in max_num
    temp=max_num;
    while(temp>0) {
        max_digits++;
        temp=temp>>1;
    }

// Step-3 : Run a for loop for max no. of digits
    for(int i=max_digits; i>=0; i--) {
        counter=0;
        for(int j=0; j<n; j++) {
            temp_pattern = pattern|(1<<(i-1));
            if((temp_pattern&arr[j])==temp_pattern) {
                counter++;
            } 
        }
        if(counter>1) {
            pattern = temp_pattern;
        }
    }
   
return pattern;
}
 
// Driver function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        cout <<  maxAND(arr,n)<<endl;
    }
    return 0;
}
