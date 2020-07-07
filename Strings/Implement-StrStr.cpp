// Problem URL :- https://practice.geeksforgeeks.org/problems/implement-strstr/1

#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends
/* The function should return position where the target string 
   matches the string str
Your are required to complete this method */
int strstr(string s, string x)
{
     //Your code here
    int slen = s.length();
    int temp = s.find(x);
    if(temp<slen) return temp;
    return -1;
    
}
