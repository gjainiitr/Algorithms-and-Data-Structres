// Problem URL :- https://practice.geeksforgeeks.org/problems/removing-consecutive-duplicates-1587115621/1

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to print string after removing consecutive duplicates


string removeConsecutiveDuplicates(string s)
{
    // Your code here
    int n = s.length();
    stack<char> myStack;
    myStack.push(s[0]);
    
    for(int i=1; i<n; i++) {
        if(myStack.top()==s[i]) continue;
        else myStack.push(s[i]);
    }
    n = myStack.size();
    char arr[n];
    for(int i=n-1; i>=0; i--) {
        arr[i]=myStack.top();
        myStack.pop();
    }
    string out="";
    for(int i=0; i<n; i++) out+=arr[i];
    return out;
}

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        cout<<removeConsecutiveDuplicates(s)<<endl;
    }
    
	return 0;
}  // } Driver Code Ends
