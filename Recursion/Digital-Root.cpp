// Problem URL :- https://practice.geeksforgeeks.org/problems/digital-root/1



#include <iostream>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
//Complete this function
int digitalRoot(int n)
{
    // No variables, no loops
    //Base case
    if(n<10) return n;
    //return and recursion
    return(digitalRoot(n/10 + n%10));
}


int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    
	    cout<<digitalRoot(n)<<endl;
	    
	    
	}
	return 0;
}
