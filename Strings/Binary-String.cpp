// Problem URL :- https://practice.geeksforgeeks.org/problems/binary-string-1587115620/1

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*  Function to count the number of substrings 
*   starting and ending with 1
*   n: size of string
*   a: input string
*/
long binarySubstring(int n, string a){
    
    // Your code here n*(n-1)/2;
    int count=0;
    for(int i=0; i<n; i++) {
        if(a[i]=='1') count++;
    }
    return count*(count-1)/2;
}


// { Driver Code Starts.

int main()
{
    int t,n,count;
    string a;
    cin>>t;
    while(t--)
    {
        count = 0;
        cin >> n;
        cin >> a;
        
        cout << binarySubstring(n, a) << endl;
    }
}
  // } Driver Code Ends
