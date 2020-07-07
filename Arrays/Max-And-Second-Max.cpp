// Problem URL :- https://practice.geeksforgeeks.org/problems/max-and-second-max/1


// CPP code to find largest and 
// second largest element in the array

#include <bits/stdc++.h>
using namespace std;

void largestAndSecondLargest(int, int[]);

/*This is a function problem.You only need to complete the function given below*/
     
/* Function to find largest and second largest element
*sizeOfArray : number of elements in the array
* arr = input array
*/
void largestAndSecondLargest(int sizeOfArray, int arr[]){
    int max = INT_MIN, max2= INT_MIN;
    
    /*********************************
     * Your code here
     * This function should print 
     * max and second max
     * *******************************/
     for(int i=0; i<sizeOfArray; i++) {
        if(arr[i]>max && arr[i]>max2) {
            max2 = max;
            max = arr[i];
        }
        if(arr[i]<max && arr[i]>max2) {
            max2 = arr[i];
        }
     }
     if(max2 == INT_MIN) max2 = -1;
     cout << max << " " << max2 << endl;
}

// Driver Code
int main() {
	
	// Testcase input
	int testcases;
	cin >> testcases;
    
    // Looping through all testcases
	while(testcases--){
	    int sizeOfArray;
	    cin >> sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    // Array input
	    for(int index = 0; index < sizeOfArray; index++){
	        cin >> arr[index];
	    }
	    
	    largestAndSecondLargest(sizeOfArray, arr);
	}
	
	return 0;
}
