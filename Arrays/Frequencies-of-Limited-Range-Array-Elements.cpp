// Problem URL :- https://practice.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1

#include<bits/stdc++.h>
using namespace std; 

/*This is a function problem.You only need to complete the function given below*/
// Function to count frequencies of elements in the array
// arr: input array
// n: size of array
void printfrequency(int arr[], int n)
{   int temp;
	// Your code herre
	for(int i=0; i<n; i++) {
	    temp = arr[i]%(n+1);
	    arr[temp-1] += (n+1);
	}
	for(int i=0; i<n; i++) {
	    arr[i] = arr[i]/(n+1);
	}
	for(int i=0; i<n; i++) cout<<arr[i]<<' ';
} 


int main() 
{ 
	long long t;
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n; // taking input size of array
	    
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i]; // input elements of array
	    }
	    
	    printfrequency(arr,n); // print frequency of elements 
	    cout << endl;
	}
	
	return 0; 
}
