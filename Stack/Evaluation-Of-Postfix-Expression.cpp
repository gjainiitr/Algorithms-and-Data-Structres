// Problem URL :- https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

int find(int a, char c, int b) {
    if(c=='+') return (a+b);
    else if(c=='*') return (a*b);
    else if(c=='-') return (a-b);
    else return (a/b);
}
// The main function that returns value of a given postfix expression
int evaluatePostfix(string &str)
{
    // Your code here
    stack<int> s;
    int size = str.length();
    int second;
    int first;
    for(int i=0; i<size; i++) {
        if(str[i]=='+'||str[i]=='/'||str[i]=='*'||str[i]=='-') {
            second = s.top();
            s.pop();
            first = s.top();
            s.pop();
            first = find(first,str[i],second);
            // if(s.empty()) return first;
            s.push(first);
        } else {
            s.push(str[i]-'0');
        } 
    }
    return s.top();
    // return res;
}


// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string str;
        cin>>str;
    
    cout<<evaluatePostfix(str)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
