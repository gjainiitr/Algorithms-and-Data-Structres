// Problem URL :- https://practice.geeksforgeeks.org/problems/gray-code-1587115620/1


#include<bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
//  Function to find the gray code of given number N
int greyConverter(int n)
{
    int temp,counter=0,result,var1,var2;
    // Your code here
    //Step-1 Convert given no. to gray code.
    temp=n;
    while(temp>0) {
        temp = temp>>1;
        counter++;
    };
    result = n>>counter;
    while(counter>0) {
        var1 = (n>>counter)&1;
        var2 = (n>>(counter-1))&1; //var1^var2
        result = (result<<1) + var1^var2;
        counter--;
    };
    return result;
}

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin >> n;
        cout << greyConverter(n) << endl;
    }
}

