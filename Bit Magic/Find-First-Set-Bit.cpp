// Problem URL :- https://practice.geeksforgeeks.org/problems/find-first-set-bit-1587115620/1



#include<bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*  function to find position of first set 
    bit in the given number
 * n: given input for which we want to get
      the position of first set bit
 */
unsigned int getFirstSetBit(int n){
    //your code here
    int i=1;
    if(n==0) return 0;
    
    //Loop continues for n>0
    while(n>0) {
        if(n%2) return i; 
        i++;
        n=n>>1;
    }
}

// Driver code
int main()
{
    int t;
    cin>>t; // testcases
    while(t--)
    {
        int n;
        cin>>n; //input n
        printf("%u\n", getFirstSetBit(n)); // function to get answer
    }
	return 0;
}

