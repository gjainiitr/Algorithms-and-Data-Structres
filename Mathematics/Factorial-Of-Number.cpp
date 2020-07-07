// Problem URL :- https://practice.geeksforgeeks.org/problems/factorial-of-number/1


#include <bits/stdc++.h>
using namespace std;
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
//Complete this function
long long factorial (int N)
{
    long long P=1;
    for(int i=1; i<=N; i++) P*=i;
    return P;
}

int main()
{
    int T,N;
    cin>>T;  //input number of testcases
    while(T--)
    {
        cin>>N; //input n
        cout<<factorial(N)<<endl;
    }
    return 0;
}

