// Problem URL :- https://practice.geeksforgeeks.org/problems/modular-multiplicative-inverse-1587115620/1


#include<iostream>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
//Complete this function
int modInverse(int a, int m)
{
    //Your code here
    for(int i=1; i<m; i++) {
        if(((i*a)%m)==1) return i;
    }
    return -1;
}

int main()
{
	int T;
	cin>>T;
	while(T--){
		int a,m;
		cin>>a>>m;
		cout << modInverse(a, m)<<endl;
	}
    return 0;
}
