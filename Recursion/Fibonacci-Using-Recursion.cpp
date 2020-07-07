// Problem URL :- https://practice.geeksforgeeks.org/problems/fibonacci-using-recursion/1


#include <bits/stdc++.h>
using namespace std;
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
//Complete this function
long long fibonacci(int n)
{
    //Your code here
    // if(n==0) return 1;
    if(n==1) return 1;
    if(n==0) return 0;
    return (fibonacci(n-1) + fibonacci(n-2));
}




int main() {
	int T;
	cin>>T;
	while (T--)
	{
	    int n;
	    cin>>n;
	    
	    cout<<fibonacci(n)<<endl;
	    
	    
	}
	return 0;
}
