// Problem URL :- https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1


#include<iostream>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
// Function to count set bits in the given number x
// n: input to count the number of set bits
int countSetBits(int n){
    //your code here
    int counter=0,p;
    for(int i=0; i<=n; i++) {
        p=i;
        while(p>0) {
            if(p%2) counter++;
            p=p>>1;
        }
    }
    return counter;
}

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       
	       cout << countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
