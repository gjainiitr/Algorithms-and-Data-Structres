// Problem URL :- https://practice.geeksforgeeks.org/problems/gp-term/1


#include<bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
//Complete this function
double termOfGP(int A,int B,int N)
{
    //Your code here (return in double)
    double ans = A;
    N -= 1;
    for(int i=1; i<=N; i++) {
        ans = (ans*B)/A;
    }
    
    return floor(ans);
}


int main()
{
    int T; //testcases total
    cin>>T;//input the testcases

    for(int i=0;i<T;i++) //white testcases are not exhausted
    {
        int A,B;
        cin>>A>>B; //input first and second term of gp
        int N;
        cin>>N; //input n
        
        cout<<floor(termOfGP(A,B,N))<<endl;
    }

    return 0;
}


