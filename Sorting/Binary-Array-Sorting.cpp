// Problem URL := https://practice.geeksforgeeks.org/problems/binary-array-sorting-1587115620/1

// A Sample C++ program for beginners with Competitive Programming
#include <iostream>
using namespace std;

void binSort(int A[], int N);


int main() {
	int T;
	cin>>T;
	// Input the number of testcases
	while(T--)
	{
	    int N;
	    cin>>N; //Input size of array N
	    int A[N]; 
	    
	    for(int i = 0; i  < N; i++)
	      cin>>A[i];
	      
	    binSort(A,N);
	    
	    for(int x:A)
	    cout<<x<<" ";
	      
	    cout<<endl;
	}
	return 0;
}



// } Driver Code Ends


// Function to sort the array A[]
// A[]: input array
// N: input array

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void binSort(int A[], int N)
{
    int j=0;
   for(int i=0; i<N; i++) {
       if(A[i] == 0) {
           swap(A[i],A[j]);
           j++;
       }
   }
   
   /**************
    * No need to print the array
    * ************/
}

// 4 3 8 9 7 

