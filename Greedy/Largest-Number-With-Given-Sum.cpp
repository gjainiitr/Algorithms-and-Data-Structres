/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/largest-number-with-given-sum-1587115620/1
*/

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Largest Number
string largestNumber(int n, int sum){
    // Your code here
    string res="";
    int count = 0;
    while(count<n) {
        if((sum-9)>=0) {
            res += '9';
            sum-=9;
        } else if(sum!=0) {
            // int temp = sum%10;
            ostringstream str1;
            str1<<sum;
            res = res + str1.str();
            sum = 0;
        } else {
            res = res + "0";
        }
        count++;
    }
    // cout<<"This is res "<<res<<endl;
    if(sum>0) return "-1";
    else return res;
}

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n,sum;
		cin>>n>>sum;

		cout<<largestNumber(n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends
