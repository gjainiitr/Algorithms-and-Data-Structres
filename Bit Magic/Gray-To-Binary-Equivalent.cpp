// Problem URL :- https://practice.geeksforgeeks.org/problems/gray-to-binary-equivalent-1587115620/1


#include<bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
// function to conver given N Gray to Binary
int grayToBinary(int n)
{
    int counter=0,temp,result,var1,var2,temp2;
    // Your code here
    temp=n;
    //counts no. of bits in n - 1
    while(temp>0) {
        temp = temp>>1;
        counter++;
    }
    // Forming result
    result = n>>counter;
    while(counter>0) {
        var1 = (n>>(counter-1))&1; // Current Gray
        var2 = (result&1); // Previous binary
        if(var1==1) var2 = !var2; 
        result = (result<<1) + var2;
        counter--;
    }
    return result;
}

// Driver code
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
       cout<< grayToBinary(n)<<endl;
    }
}

