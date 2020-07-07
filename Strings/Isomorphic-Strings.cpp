// Problem URL :- https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1

// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

bool areIsomorphic(string, string);

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        cout<<areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}// } Driver Code Ends
// This function returns true if str1 and str2 are ismorphic
// else returns false
bool areIsomorphic(string str1, string str2)
{
    int str1len = str1.length(), str2len = str2.length();
    // Your code here
    int count1[256]={0},count2[256]={0};
    if(str1len!=str2len) return false;
    for(int i=0; i<str1len; i++) count1[str1[i]]++;
    for(int i=0; i<str1len; i++) count2[str2[i]]++;
    for(int i=0; i<str1len; i++) {
        if(count1[str1[i]]!=count2[str2[i]]) return false;
    }
    return true;
}
