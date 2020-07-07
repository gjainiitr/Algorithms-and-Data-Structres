// Problem URL :- https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to calculate span
// price[]: price array in input
// n: size of array
void calculateSpan(int price[], int n, int S[])
{
   // Your code here
   stack<int> s;
   s.push(0); S[0]=1;
   for(int i=1; i<n; i++) {
       while(!s.empty()) {
           if(price[s.top()]<=price[i]) s.pop();
           else break;
       }
       if(s.empty()) S[i]=i+1;
       else S[i] = i-s.top();
       s.push(i);
   }
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n],s[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		calculateSpan(a, n, s);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends
