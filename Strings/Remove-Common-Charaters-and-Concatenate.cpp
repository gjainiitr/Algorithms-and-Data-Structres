// Problem URL :- https://practice.geeksforgeeks.org/problems/remove-common-characters-and-concatenate-1587115621/1

// C++ program Find concatenated string with 
// uncommon characters of given strings 
#include <bits/stdc++.h> 
using namespace std; 

string concatenatedString(string, string);

/* Driver program to test above function */
int main() 
{ 
	int t;
	cin >> t;
	
	while(t--){
    	string s1, s2;
    	cin >> s1 >> s2;
    	string res = concatenatedString(s1, s2);
    	
    	if(res.length() >= 1) cout << res << endl;
    	else cout << "-1" << endl;
	
	}
	return 0; 
}
// } Driver Code Ends
// Function which concatenate two strings
// after removing common characters
string concatenatedString(string s1, string s2) 
{ 
    // Your code here
    string result;
    int s1len = s1.length(),s2len = s2.length();
    for(int i=0; i<s1len; i++) {
        if(s2.find(s1[i])<s2len) continue;
        else result += s1[i];
    }
    for(int i=0; i<s2len; i++) {
        if(s1.find(s2[i])<s1len) continue;
        else result += s2[i];
    }
    return result;
}

