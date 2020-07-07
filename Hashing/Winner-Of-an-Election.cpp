// Problem URL :- https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1

#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;

void winner(string arr[],int n);


int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        
        winner(arr,n);
        
        cout<<endl;
        
        
    }
    return 0;
}
// } Driver Code Ends
// Funtion to find winner
// arr[]: input array
// n: size of array
void winner(string arr[],int n)
{
    //Your code here
    string resFirst;
    int resSecond=0;
    map<string,int> m;
    for(int i=0; i<n; i++) {
        m[arr[i]]++;
    }
    for(auto it=m.begin(); it!=m.end(); it++) {
        if((it->second)>resSecond) {
            resFirst = it->first;
            resSecond = it->second;
        }
    }
    cout<<resFirst<<' '<<resSecond;
}
