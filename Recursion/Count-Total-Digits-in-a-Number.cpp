// Problem URL :- https://practice.geeksforgeeks.org/problems/count-total-digits-in-a-number/1


#include <iostream>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
//Complete this function
int countDigits(int n)
{
   //Your code here
   if(n==0) return 0;
   return(1 + countDigits(n/10));
}

int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    
	    cout<<countDigits(n)<<endl;
	    
	    
	}
	return 0;
}



