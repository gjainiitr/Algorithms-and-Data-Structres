// Problem URL :- https://practice.geeksforgeeks.org/problems/lucky-numbers2911/1

//Initial Template for C++


#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int counter=2;


 // } Driver Code Ends
//User-function template for C++

// Complete the function
// n: Input n
// counter: variable has already been declared in driver code
//          you just have to use this variable.
// Return True if the given number is a lucky number else return False

bool isLucky(int n) {
    // add code here
    int p = n;
    int i = 2;
    while(p>=i) {
        if(p%i==0) return false;
        p=p-(p/i);
        i++;
    }
    if(p<i) return true;
}

// { Driver Code Starts.

/*Driver function to test above function*/
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin>>n;
        if(isLucky(n))
            cout<<"1\n";
        else
            cout<<"0\n";
        counter = 2;
    }
    return 0;
}  // } Driver Code Ends
