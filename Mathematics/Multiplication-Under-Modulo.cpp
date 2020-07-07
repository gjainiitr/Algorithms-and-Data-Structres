// Problem URL :- https://practice.geeksforgeeks.org/problems/multiplication-under-modulo/1



#include <bits/stdc++.h>
using namespace std;



/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
int multiplicationUnderModulo(long long a,long long b)
{
    int M=1000000007;
    //your code here
    return ((a%M)*(b%M))%M;
}


int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    long long a;
	    long long b;
	    cin>>a>>b;
	    cout<<multiplicationUnderModulo(a,b)<<endl;
	}
	return 0;
}
