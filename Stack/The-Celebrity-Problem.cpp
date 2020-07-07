// Problem URL :- https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

#include<bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX],int n);

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;

    }
}

// } Driver Code Ends
// The task is to complete this function

// M[][]: input matrix
// n: size of matrix (n*n)
int getId(int M[MAX][MAX], int n)
{
    if(n==2) {
        if(M[0][1] && !M[1][0]) return 1;
        if(M[1][0] && !M[0][1]) return 0;
        return -1;
    }
    stack<int> s;
    for(int i=0; i<n; i++) s.push(i);
    
    int A,B,C,temp;
    
    // Push 2 random nos.
    A = s.top();
    s.pop();
    B = s.top();
    s.pop();
    
    
    // compare between 2 selected nos
    while(s.size()>1) {
        if(M[A][B]) {
            A = s.top();
            s.pop();
        } else {
            B = s.top();
            s.pop();
        }
    }
    
    C = s.top(); 
    s.pop();
    
    
    // continue from here
    if(M[C][A]) C=A;
    if(M[C][B]) C=B;
    
    // just check if C is a celebrity or not
    for(int i=0; i<n; i++) {
        if(C!=i && (M[C][i] || !M[i][C] )) return -1;
    }
    return C;
}
