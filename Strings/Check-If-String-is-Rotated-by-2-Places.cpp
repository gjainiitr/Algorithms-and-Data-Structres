// Problem URL :- https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places-1587115620/1

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*  Function to check if str1 can be formed from
*   str2 after rotation by 2 places
*/
bool isRotated(string str1, string str2)
{
    // Your code here
    int i;
    int count;
    int str1len = str1.length(), str2len = str2.length();
    if(str1len!=str2len) return false;
    
    for(i=0; i<str1len; i++) {
        count = (str1len-2+i)%str1len;
        if(str1[i]!=str2[count]) break;
    }
    if(i==str1len) return true;
    for(i=0; i<str1len; i++) {
        count = (str2len-2+i)%str2len;
        if(str2[i]!=str1[count]) break;
    }
    if(i==str1len) return true;
    return false;
}


// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		cout<<isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
