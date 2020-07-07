// Problem URL :- https://practice.geeksforgeeks.org/problems/digits-in-factorial/1



#include<bits/stdc++.h>
using namespace std;


/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
//You need to complete this function
int digitsInFactorial(int N)
{
    //Your code here
    double num=0;
    for(int i=1; i<=N; i++) {
        num += log10(i);
    }
    return 1 + floor(num);
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        cout<<digitsInFactorial(N)<<endl;
    }
    return 0;
}

