// Program URL :- https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

// s is the given string
// pat is the given text 

string smallestWindow (string s, string pat){
    // Your code here
    int start_index=-1, start=0, count=0, window_size=0, min_size=s.length()+1;
    int len1=s.length(), len2=pat.length();
    int j=0;
    
    int arr1[128]={0}, arr2[128]={0};
    // for(int i=0; i<len1; i++) arr1[s[i]]++;
    for(int i=0; i<len2; i++) arr2[pat[i]]++;
    
    for(j=0; j<len1; j++) {
        arr1[s[j]]++;
        if(arr2[s[j]]!=0 && arr1[s[j]]<=arr2[s[j]]) count++;
        
        if(count==len2) {
            while(arr2[s[start]]==0 || arr1[s[start]]>arr2[s[start]]) {
                arr1[s[start]]--;
                start++;
            }
            
            window_size = j-start+1;
            if(window_size<min_size) {
                start_index=start;
                min_size=window_size;
            }
            
        }
    }
    
    if(start_index==(-1)) return "-1";
    else return s.substr(start_index,min_size);
}


// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        
        cout<<smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
