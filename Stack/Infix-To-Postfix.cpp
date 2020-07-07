// Problem URL :- https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1

// C++ implementation to convert infix expression to postfix
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

// The main function to convert infix expression
//to postfix expression
string infixToPostfix(string s)
{
    // Your code here
    unordered_map<char,int> m;
    m['+']=1;
    m['-']=1;
    m['*']=2;
    m['/']=2;
    m['^']=3;
    m['(']=0;
    int size = s.length();
    stack<char> stk;
    string res="";
    for(int i=0; i<size; i++) {
        if(s[i]=='(') stk.push(s[i]);
        else if(s[i]==')') {
            while(!stk.empty() && stk.top()!='(') {
                res+=stk.top();
                stk.pop();
            }
            stk.pop();
        } else if(m.find(s[i])!=m.end()) { // its an operator
            int valOut;
            if(!stk.empty() && stk.top()!='(') { // ignore value calculation when '(' is at top
                valOut = m[s[i]];
                while(!stk.empty() && stk.top()!='(' && m[stk.top()]>=valOut) {
                    res += stk.top();
                    stk.pop();
                }
            }
            stk.push(s[i]);
        } else {
            res+=s[i];
        }
    }
    while(!stk.empty()) {
        res+=stk.top();
        stk.pop();
    }
    return res;
}


// { Driver Code Starts.
//Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string exp;
        cin>>exp;
        cout<<infixToPostfix(exp)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
