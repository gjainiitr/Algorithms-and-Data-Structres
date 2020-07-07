// Problem URL :- https://practice.geeksforgeeks.org/problems/removing-consecutive-duplicates-2-1587115621/1

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return string after removing consecutive duplicates

// Function to remove pair of characters
string removePair(string str){
    // Your code here
    stack <char> s1, s2;
    for(int i=0; i<str.length(); i++) s1.push(str[i]);
    
    bool noRepititions=false;
    int size;
    char temp;
    
    
    
    while(noRepititions==false && s1.size()>0) {
        noRepititions=true;
        while(s1.size()!=0) {
            temp=s1.top();
            s1.pop();
            if(s1.size()!=0 && s1.top()==temp) {
                s1.pop();
            } else {
                s2.push(temp);
            }
        }
        
        while(s2.size()!=0) {
            temp=s2.top();
            s2.pop();
            if(s2.size()!=0 && s2.top()==temp) {
                s2.pop();
                noRepititions=false;
            } else {
                s1.push(temp);
            }
        }
    }

    if(s1.size()==0) return "Empty String";
    string out="";
    
    size = s1.size();
    
    for(int i=0; i<size; i++) {
        out = s1.top() + out;
        s1.pop();
    }
    
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
        
        string ans = removePair (s);
        
        if(ans=="")
            cout<<"Empty String"<<endl;
        else
            cout<<ans<<endl;
    }
    
	return 0;
}  // } Driver Code Ends
