// Problem URL :- https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

#include<bits/stdc++.h>

using namespace std;

/*This is a function problem.You only need to complete the function given below*/
   
// function to find the trapped water in between buildings
// arr: input array
// n: size of array
int trappingWater(int arr[], int n){
    // Your code here
    int lmax[n], rmax[n],sum=0;
    
    lmax[0] = arr[0];
    for(int i=1; i<n; i++) {
        lmax[i] = arr[i]>lmax[i-1]?arr[i]:lmax[i-1]; // max(arr[i], lmax[i-1]);
    }
    
    rmax[n-1] = arr[n-1];
    for(int i=n-2; i>=0; i--) {
        rmax[i] = arr[i]>rmax[i+1]?arr[i]:rmax[i+1];
    }
    
    for(int i=1; i<n-1; i++) {
        sum+= (lmax[i]>rmax[i]?rmax[i]:lmax[i]) - arr[i];
    }
    return sum;
}

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        
        cin >> n;
        
        int a[n];
        
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        
        cout << trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
