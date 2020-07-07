// Problem URL :- https://practice.geeksforgeeks.org/problems/power-using-recursion/1



#include <iostream>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
//Complete this function
int RecursivePower(int n,int p)
{
    //Your code here
    if(p==1) return n;
    return(n*RecursivePower(n,p-1));
}



int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n,p;
	    cin>>n>>p;
	    cout<<RecursivePower(n,p)<<endl;
	}
	return 0;
}
