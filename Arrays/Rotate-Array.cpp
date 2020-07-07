// Problem URL :- https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1

#include<bits/stdc++.h>
using namespace std;


/*This is a function problem.You only need to complete the function given below*/
// This function rotate array by D elements
// arr: input elements
// n: size of the array
void rotateArr(int arr[], int d, int n){
    // 1 2 3 4 5 by 2 becomes 3 4 5 1 2
    // Your code here
    int arr2[d];
    
    // Step-1 : Copying first d elements
    for(int i=0; i<d; i++) {
        arr2[i] = arr[i];
    }
    
    // Step-2 : Shifting elements by d to the left
    for(int i=d; i<n; i++) {
        arr[i-d] = arr[i];
    }
    
    // Step-3 : Copying d elements to the end
    for(int i=n-d; i<n; i++) {
        arr[i] = arr2[i-n+d];
    }
}


int main() {
	//code
	
	int t;
	cin >> t;
	
	while(t--){
	    int n, d;
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    
	    rotateArr(arr, d,n);
	    
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	    
	}
	
	return 0;
}
