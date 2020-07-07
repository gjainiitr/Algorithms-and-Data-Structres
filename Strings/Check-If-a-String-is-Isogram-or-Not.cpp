// Problem URL :- https://practice.geeksforgeeks.org/problems/check-if-a-string-is-isogram-or-not-1587115620/1

#include<bits/stdc++.h>
using namespace std;

bool isIsogram(string s);

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        
        string s;
        cin>>s;
        
        cout<<isIsogram(s)<<endl;
        
    }
	return 0;
}// } Driver Code Ends
//Complete this function
bool isIsogram(string s)
{
    //Your code here
    int slen = s.length();
    int count[256]={0};
    // if(str1len!=str2len) return false;
    for(int i=0; i<slen; i++) count[s[i]]++;
    // for(int i=0; i<str1len; i++) count2[str2[i]]++;
    for(int i=0; i<slen; i++) {
        // if(count1[str1[i]]!=count2[str2[i]]) return false;
        if(count[s[i]]>1) return false;
    }
    return true;
}
