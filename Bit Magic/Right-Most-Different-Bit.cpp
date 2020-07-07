// Problem URL :- https://practice.geeksforgeeks.org/problems/rightmost-different-bit-1587115621/1


#include <bits/stdc++.h>
using namespace std;
 
// Function to get rightmost set bit
int getRightMostSetBit(int n)
{
    return log2(n & -n) + 1; //finding the rightmost set bit of a number
}
 
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*  Function to find the first position with different bits
*   This function returns the position with different bit
*/
int posOfRightMostDiffBit(int m, int n)
{
    
    // Your code here
    if (m==n) return -1;
    int i = 1;
    
    while(n>0 || m>0)
    {
        // Check remainder of each no. on dividing by 2
        if(m%2 != n%2) return i;    
        // Right shift each position and increment counter
        m = m>>1; n = n>>1; i += 1;
    }
        
}

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         cout << posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
} 
