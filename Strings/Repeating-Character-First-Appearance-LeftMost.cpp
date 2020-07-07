// Problem URL :- https://practice.geeksforgeeks.org/problems/repeating-character-first-appearance-leftmost/1

//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

//Return the index of the character or return -1
int repeatedCharacter (string s) 
{ 
    //Your code here
    int slen = s.length();
    int count[256] = {0};
    for(int i=0; i<slen; i++) count[s[i]]++;
    for(int i=0; i<slen;i++) if(count[s[i]]>1) return i;
    return -1;  
} 

// { Driver Code Starts.


int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    string s;
	    cin>>s;
	    int index = repeatedCharacter(s); 
        if (index == -1) 
            cout<<-1<<endl;
        else
            cout<<s[index]<<endl;
	}
	return 0;
}
  // } Driver Code Ends
