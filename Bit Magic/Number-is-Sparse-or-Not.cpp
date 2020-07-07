// Problem URL :- https://practice.geeksforgeeks.org/problems/number-is-sparse-or-not-1587115620/1


// C++ program to check if n is sparse or not
#include<iostream>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
// function to check if the number is sparse
// n : is the number to check if it is sparse
bool isSparse(int n){
    
    bool sparse = 1;
    if(n&(n>>1)) {
        sparse = 0;
    }
    return sparse;
}

// Driver Code
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        
        if(isSparse(n)){
            cout << "1" << endl;
        }
        else cout << "0" << endl;
        
    }
    return 0;
}
