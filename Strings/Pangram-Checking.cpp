// Problem URL :- https://practice.geeksforgeeks.org/problems/pangram-checking-1587115620/1



#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Returns true if the string is pangram else false
bool checkPangram (string &str)
{
    // your code here
    int i,j;
    int count[26] = {0};
    int temp, slen = str.length();
    for(i=0; i<slen; i++) {
        temp = (int)str[i];
        if(temp>64) {
            if(temp<91) {
                count[temp-65]++;
            } else {
                count[temp-97]++;
            }
        }
    }
    for(j=0; j<26; j++) {
        if(count[j]==0) return false;
    }
    return true;
}



// { Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string str;
        getline(cin, str);
        
        if (checkPangram(str) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}
  // } Driver Code Ends
