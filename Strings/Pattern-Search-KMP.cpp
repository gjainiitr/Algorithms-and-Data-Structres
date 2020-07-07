// Problem URL :- https://practice.geeksforgeeks.org/problems/pattern-search-kmp/1

//Initial Template for C++

// C++ program for implementation of KMP pattern searching 
// algorithm 
#include <bits/stdc++.h> 

using namespace std;


 // } Driver Code Ends

//User function Template for C++

// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(string pat, int M, int* lps) 
{ 
	// Your code here
	int len = 0;
	lps[0]=0;
	int i=1;
	
	while(i<M) {
	    if(pat[len]==pat[i]) {
	        len++;
	        lps[i]=len;
	        i++;
	    } else {
	        if(len==0) {
	            lps[i]=0;
	            i++;
	        } else {
	            len = lps[len-1];
	        }
	    }
	}
	return;
} 

// Returns true if pat found in txt
bool KMPSearch(string pat, string str) {
    // Your code here
    int i=0,j=0;
    int n=str.length(), m=pat.length();
    int* lps = new int[m];
    computeLPSArray(pat,m,lps);
    while(i<n) {
        if(str[i]==pat[j]) {
            i++;
            j++;
        }
        if(j==m) {
            return true;
            j = lps[j-1];
        }
        if(i<n && str[i]!=pat[j]) {
            if(j==0) {
                i++;
            } else {
                j=lps[j-1];
            }
        }
    }
    return false;
}

// { Driver Code Starts.

// Driver program to test above function 
int main() 
{ 
    int t;
    std::cin >> t;
    
    while(t--){
        string s, pat;
        cin >> s >> pat;
        if(KMPSearch(pat, s)){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
    
	return 0;
} 
  // } Driver Code Ends
