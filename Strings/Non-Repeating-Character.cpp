// Problem URL :- https://practice.geeksforgeeks.org/problems/non-repeating-character-1587115620/1


#include <bits/stdc++.h>
using namespace std;

char nonrepeatingCharacter(string S);

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    
        char ans = nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends

// Complete this function
char nonrepeatingCharacter(string S)
{
   //Your code here
    int slen = S.length();
    int count[256] = {0};
    for(int i=0; i<slen; i++) count[S[i]]++;
    for(int i=0; i<slen;i++) if(count[S[i]]==1) return S[i];
    return '$';
}

