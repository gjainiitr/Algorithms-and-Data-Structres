// Problem URL :- https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1


#include <bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
// Function to check if Kth bit is set or not
bool checkKthBit(int n, int k){
    bool isSet = 0;
    // Your code here
    // It can be a one liner logic!! Think of it!!
    if((n>>k)%2 != 0) isSet = 1;
    return isSet;
}

// Driver Code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    long long n;
	    cin>>n;
	    int k;
	    cin>>k;
	    
	    if(checkKthBit(n, k))
	        cout << "Yes" << endl;
	    else
	        cout << "No" << endl;
	}
	return 0;
}
