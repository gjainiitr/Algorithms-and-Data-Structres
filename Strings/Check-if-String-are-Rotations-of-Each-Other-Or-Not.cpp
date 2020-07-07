// Problem URL :- https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1

#include <bits/stdc++.h>
using namespace std;

bool areRotations(string, string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        cout<<areRotations(s1,s2)<<endl;

    }
    return 0;
}
// } Driver Code Ends
/*  Function to check if two strings are rotations of each other
*   s1, s2: are the input strings
*/
bool areRotations(string s1,string s2)
{
    // Your code here
    int s1len = s1.length(),s2len = s2.length();
    if(s1len!=s2len) return false;
    s1 = s1+s1;
    
    if(s1.find(s2)<s1len) return true;
    return false;
    
}
