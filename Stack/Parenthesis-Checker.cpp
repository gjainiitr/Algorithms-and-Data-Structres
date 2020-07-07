// Problem URL :- https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return if the paranthesis are balanced or not
bool isMatch(char a, char b) {
    if(a=='{'&&b=='}') return true;
    if(a=='['&&b==']') return true;
    if(a=='('&&b==')') return true;
    return false;
}
bool ispar(string x)
{
    // Your code here
    stack<char> s;
    for(int i=0; i<x.length(); i++) {
        if(x[i]=='{'||x[i]=='['||x[i]=='(') {
            s.push(x[i]);
        } else {
            if(s.empty()) return false;
            if(isMatch(s.top(),x[i])== false) return false;
            s.pop();
        }
    }
    if(!s.empty()) return false;
    else return true;
}


// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       if(ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
