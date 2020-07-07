// Problem URL :- https://practice.geeksforgeeks.org/problems/sum-of-digits-of-a-number/1




#include <iostream>
using namespace std;


/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
// Complete this function
int sumOfDigits(int n)
{
    //Your code here
    //Sum of the digits
    
    //Base case
    if(n==0) return 0;
    //return and recursion
    return((n%10) + sumOfDigits(n/10));
}


int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    
	    cout<<sumOfDigits(n)<<endl;
	    
	    
	}
	return 0;
}
