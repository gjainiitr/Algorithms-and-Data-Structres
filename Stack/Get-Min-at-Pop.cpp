// Problem URL :- https://practice.geeksforgeeks.org/problems/get-min-at-pop/1
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

stack<int>_push(int arr[],int n);

void _getMinAtPop(stack<int>s);

 // } Driver Code Ends
//User function Template for C++

/* inserts elements of the array into 
   stack and return the stack
*/
stack<int> as;
stack<int>_push(int arr[],int n)
{
   // your code here
   stack<int>s;
   for(int i=0; i<n; i++) {
       s.push(arr[i]);
       if(as.empty()) as.push(arr[i]);
       else {
           if(as.top()>=s.top()) as.push(arr[i]);
       }
   }
   return s;
}

/* print minimum element of the stack each time
   after popping
*/
void _getMinAtPop(stack<int>s)
{
    while(!s.empty()) {
        cout<<as.top()<<' ';
        if(s.top()==as.top()) as.pop();
        s.pop();
    }
}

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    stack<int>mys=_push(arr,n);
	    _getMinAtPop(mys);
	    cout<<endl;
	    
	    
	    
	}
	return 0;
}

  // } Driver Code Ends
