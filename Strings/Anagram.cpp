// Program URL :- https://practice.geeksforgeeks.org/problems/anagram-1587115620/1

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*  Function to check if two strings are anagram
*   c, d: input string
*/
bool isAnagram(string c, string d){
    
    // Your code here
    int clen = c.length();
    int dlen = d.length();
    if(clen!=dlen) return false;
    int count[256] = {0};
    for(int i=0; i<clen; i++) count[c[i]]++;
    for(int j=0; j<dlen; j++) count[d[j]]--;
    for(int i=0; i<256; i++) if(count[i]!=0) return false;
    return true;
}


// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;

        if(isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends
