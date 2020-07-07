// Problem URL :- https://practice.geeksforgeeks.org/problems/longest-consecutive-1s-1587115620/1


#include <iostream>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*  Function to calculate the largest consecutive ones
*   x: given input to calculate the largest consecutive ones
*/
int maxConsecutiveOnes(int x)
{
    int c1=1,rem=0, c2=1;
    // Your code here
    // To find -> Length of the longest consecutive 1s
    while(x>0) {
        if((x%2)!=0 && (x>>1)%2!=0) {
            c1 += 1;
        } else {
            c2 = (c1>c2)?c1:c2;
            c1 = 1;
        }
        
        x = x>>1;
    }
    return c2;
}


// Driver Code
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<maxConsecutiveOnes(n)<<endl;
	}
	return 0;
}
