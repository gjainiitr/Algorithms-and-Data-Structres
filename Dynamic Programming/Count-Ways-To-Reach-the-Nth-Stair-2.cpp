/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1
*/

#include<bits/stdc++.h>
using namespace std;

long long mod =1000000007;

long long countWays(int);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m;
        cin>>m;
        cout<<countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}// } Driver Code Ends
// function to count ways to reach mth stair
long long countWays(int m){
    // your code here
    return ((m/2)+1);
}

