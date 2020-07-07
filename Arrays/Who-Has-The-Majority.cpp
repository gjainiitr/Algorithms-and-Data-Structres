// Problem URL :- https://practice.geeksforgeeks.org/problems/who-has-the-majority/1


#include <bits/stdc++.h>
using namespace std;

int majorityWins(int arr[], int n, int x,int y);
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*Geeks, you have to complete this function*/
int majorityWins(int arr[], int n, int x,int y)
{
    int count_x=0;//counter to count frequency of x
    int count_y=0;//counter to count frequency of y
    
    
    /***********************************************
           Delete this comment, and write your code 
                 Your code goes here, Geeks
    ***********************************************/
    for(int i=0; i<n; i++) {
        if(arr[i] == x) count_x++;
        if(arr[i] == y) count_y++;
    }
    
    if(count_x>count_y)
    //Complete this
    return x;
    else if(count_y>count_x)
    //Complete this
    return y;
    else
    //Complete this
    return (x>y?y:x);
    
}

int main() {
    
    int t; //Testcases
    cin>>t; // Input the testcases
    while(t--) //Until all testcases are exhausted
    {
        int n; //Size of array
        cin>>n; //Input the size
        int arr[n]; //Declaring array of size n
        for(int i=0;i<n;i++) // Running a loop to input all elements of arr
        cin>>arr[i];
        
        int x,y; //declare x and y
        cin>>x>>y; // input x and y
        cout << majorityWins(arr,n,x,y) << endl; //calling the function that you complete
        
    }
    
	return 0;
}
