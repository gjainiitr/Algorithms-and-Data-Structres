// Problem URL :- https://practice.geeksforgeeks.org/problems/addition-under-modulo/1



#include <bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
int sumUnderModulo(long long a,long long b)
{
    long long int M=1000000007;
    //your code here
    return ((a%M)+(b%M))%M;
}


int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    long long a;
	    long long b;
	    cin>>a>>b;
	    cout<<sumUnderModulo(a,b)<<endl;
	}
	return 0;
}
