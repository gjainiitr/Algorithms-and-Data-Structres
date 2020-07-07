/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1
*/
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

long long sumSubstrings(string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        cout << sumSubstrings(s) << endl;
        
    }
    return 0;
}
// } Driver Code Ends
// function to find sum of all possible substrings of the given string
long long sumSubstrings(string s){
    // long long p = 1000000007;
    int size = s.length();
    long long res=0;
    for(int i=0; i<size; i++) {
        long long a=0;
        for(int j=i; j<size; j++) {
            a = ((10*a)%1000000007 + (s[j]-'0'));
            res = (res + a)%1000000007;
        }
    }
    return res;
}
