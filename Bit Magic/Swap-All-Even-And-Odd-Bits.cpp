// Problem URL :- https://practice.geeksforgeeks.org/problems/swap-all-odd-and-even-bits-1587115621/1


#include<bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
// function to swap odd and even bits
unsigned int swapBits(unsigned int n)
{
	unsigned int odd, even;
	// Your code here
	odd = (n&85)<<1;
	even = (n&42)>>1;
	return (odd+even);
}

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		unsigned int n;
		cin>>n;
		cout << swapBits(n) << endl;
	}
	return 0;
}


