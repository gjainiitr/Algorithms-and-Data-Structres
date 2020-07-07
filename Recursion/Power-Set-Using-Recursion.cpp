// Problem URL :- https://practice.geeksforgeeks.org/problems/power-set-using-recursion/1

//Initial Template for C++


// CPP program to generate power set
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


void Set(string s, int index, string curr, vector<string> &result) {
    int n = s.length();
    if(index == n) {
        result.push_back(curr);
        return;
    }
    Set(s,index+1,curr,result);
    Set(s,index+1,curr+s[index],result);
}

//Complete this function
vector <string> powerSet(string s)
{
   //Your code here
   vector<string> result;
   Set(s,0,"",result);
   return result;
}




// { Driver Code Starts.


// Driver code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        vector<string> ans = powerSet(s);
        sort(ans.begin(),ans.end());
        for(auto x:ans)
        cout<<x<<" ";
        cout<<endl;
        
        
    }

return 0;
}   // } Driver Code Ends
