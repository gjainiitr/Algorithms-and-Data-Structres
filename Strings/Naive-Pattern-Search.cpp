// Problem URL :- https://practice.geeksforgeeks.org/problems/naive-pattern-search-1587115620/1

// C++ program for Naive Pattern 
// Searching algorithm 
#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
/*  Function to serach pattern in the given string
*   pat: pattern given in input
*   txt: string given in the input
*/
bool search(string pat, string txt) 
{ 
	
	// Your code here
	bool areRotations = false;
    // string text = "ABCDABCE";
// m-2 All characters in pattern are different
    // string pat = "ABCE";
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
        i++;
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
}
  // } Driver Code Ends
