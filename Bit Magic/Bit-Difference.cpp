// Problem URL :- https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1


#include<bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
// Function to find number of bits to be flip
// to convert A to B
int countBitsFlip(int a, int b){
    int count=0;
    //your code here
    while(a>0||b>0) {
        if(!(a%2 == b%2)) count++;
        a=a>>1; b=b>>1;
    }
    return count;
}

// Driver Code
int main()
{
	int t;
	cin>>t;// input the testcases
	while(t--) //while testcases exist
	{
		int a,b;
		cin>>a>>b; //input a and b

		cout<<countBitsFlip(a, b)<<endl;
	}
	return 0;
}
