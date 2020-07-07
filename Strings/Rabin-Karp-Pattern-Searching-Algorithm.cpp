// Problem URL :- https://practice.geeksforgeeks.org/problems/rabin-karp-pattern-searching/1

//Initial Template for C++

/* Following program is a C implementation of 
Rabin Karp. Algorithm given in the CLRS book */
#include<bits/stdc++.h>

using namespace std;

bool search(string, string, int);


 // } Driver Code Ends

//User function Template for C++

// d is the number of characters in the input alphabet 
#define d 256 

/* pat -> pattern 
	txt -> text 
	q -> A prime number 
*/
bool search(string pat, string str, int q) 
{ 
	// Your code here
    // p -> pattern hash value
    // d -> current sub string hash value
    // h -> multiplier to convert lsb to msb i.e. d^(m-1)%q;
	int p=0,l=0,h=1;
	int n=str.length(), m=pat.length();
// 	h = ((int)pow(d,m-1))%q;
    for(int i=1; i<m; i++) h=(h*d)%q;
	for(int i=0; i<m; i++) {
	    p = (p*d + pat[i])%q;
	    l = (l*d + str[i])%q;
	}
	
	for(int i=0; i<=n-m; i++) {
	    if(l==p) {
	        int j;
	        for(j=0; j<m; j++) {
	            if(str[i+j]!=pat[j]) break;
	        }
	        if(j==m) return true;
	    }
	    
	    if(i<n-m) {
	        l = (d*(l - h*str[i]) + str[i+m])%q;
	    
	        if(l<0) l+=q;
	    }
	}
	return false;
}  

// { Driver Code Starts.

/* Driver program to test above function */
int main() 
{ 
    int t;
    cin >> t;
    
    while(t--){
	    string s, p;
	    cin >> s >> p;
	    int q = 101; // A prime number 
	    if(search(p, s, q)) cout << "Yes" << endl;
	    else cout << "No" << endl;
    }
	return 0; 
} 
  // } Driver Code Ends
