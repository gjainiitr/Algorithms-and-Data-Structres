// Problem URL :- https://practice.geeksforgeeks.org/problems/minimum-indexed-character-1587115620/1



// C++ implementation to find the character in first 
// string that is present at minimum index in second
// string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
void printMinIndexChar(string str, string patt)
{
    // Your code here
    bool isPresent = false;
    int slen = str.length(),plen = patt.length();
    for(int i=0; i<slen; i++) {
        if(patt.find(str[i])<plen) {
            cout<<str[i];
            isPresent = true;
            break;
        }
    }
    if(!isPresent) cout<<"No character present";
}

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    string patt;
	    cin>>str;
	    cin>>patt;
	    printMinIndexChar(str, patt);
	    cout<<endl;
	}return 0;
}
  // } Driver Code Ends
