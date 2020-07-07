// Problem URL :- https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1

#include<bits/stdc++.h>
using namespace std;
#define ll long long


 // } Driver Code Ends
// Function to print all binary numbers upto n
void generate(ll n)
{
	// Your code here
	queue<string> q;
	q.push("1");
	string temp;
	for(int i=0; i<n; i++) {
	    temp = q.front();
	    cout<<temp<<' ';
	    q.pop();
	    q.push(temp+"0");
	    q.push(temp+"1");
	}
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		generate(n);
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
