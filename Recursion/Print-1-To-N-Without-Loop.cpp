// Problem URL :- https://practice.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1

#include<bits/stdc++.h>
using namespace std;

void printNos(int N);
/* Driver program to test printNos */
int main()
{
    int T;
    cin>>T;
    
    while(T--)
    {
        int N;
        cin>>N;
        printNos(N);
        
        cout<<endl;
    }
    return 0;
}/*This is a function problem.You only need to complete the function given below*/
//Complete this function
void printNos(int N)
{
    //Your code here
    // Don't assume any variable
    
    if(N!=1) printNos(N-1);
    cout<<N<<" ";
}
