// Problem URL :- https://practice.geeksforgeeks.org/problems/sum-of-numbers-in-string-1587115621/1

// C++ program to calculate sum of all numbers present
// in a string containing alphanumeric characters
#include <iostream>
using namespace std;


 // } Driver Code Ends


// Function to calculate sum of all numbers present
// in a string containing alphanumeric characters
int findSum(string str)
{
	
	// Your code here
	char temp; int value=0,result,slen = str.length();
	for(int i=0; i<slen; i++) {
	    if(str[i]<59) {
	        value*=10;
	        value+= (int)str[i]-48;
	    } else {
	        result+=value;
	        value=0;
	    }
	}
	result+=value;
	return result;
}

// { Driver Code Starts.

// Driver code
int main()
{
	// input alphanumeric string
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    cout << findSum(str);
        cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends
