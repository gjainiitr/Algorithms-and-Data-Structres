// Problem URL :- https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1

#include<bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int a[], int size)
{
    
    // your code here
    int* freq = new int[size+1];
    for(int i=0; i<size; i++) {
        freq[a[i]]++;
    }
    for(int i=0; i<=size; i++) {
        if (freq[i]>(size/2)) {
            return i;
        }
    }

    return -1;
}

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        cout << majorityElement(arr, n) << endl;
    }

    return 0;
}

