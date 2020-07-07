// Problem URL :- https://practice.geeksforgeeks.org/problems/distinct-pattern-search-1587115620/1

// C++ program for Naive Pattern 
// Searching algorithm 
#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
/*  function to search for a pattern with distinct characters
*   pat: pattern(to be searched in txt) given in the input
*   txt: string given in the input
*/
bool search(string pat, string txt) 
{ 
	
    int patlen = pat.length();
    int txtlen = txt.length();
    int i=0, j=0;
    while(i<txtlen-patlen+1) {
        for(j=0; j<patlen; j++) {
            if(txt[i+j]!=pat[j]) {
                break;
            }
        }
        if(j==patlen) {
           return true;
        }
        if(j==0) i++;
        else i+=j;
    }
    return false;
} 

// { Driver Code Starts.

// Driver Code 
int main() 
{ 
	
	int t;
	cin >> t;
	
	while(t--){
	    string s, p;
	    cin >> s >> p;
	    if(search(p, s)) cout << "Yes"; else cout << "No"; cout << endl;
	}
	
	return 0; 
}  // } Driver Code Ends
