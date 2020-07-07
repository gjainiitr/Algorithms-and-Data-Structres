// Problem URL :- https://practice.geeksforgeeks.org/problems/rank-the-permutations-1587115621/1

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

int factorial(int n) {
    int temp=1;
    for(int i=1; i<=n; i++) temp*=i;
    return temp;
}
void adjustment(int pre_sum[], char c) { // size of pre_sum is 128
    int idx = (int)c;
    for(int i=idx; i<128; i++) {
        pre_sum[i]--;
    }
}
int findRank(string s) 
{
    //Your code here
    int size = s.length();
    int fact = factorial(size);
    int freq[128]={0};
    int rank=1;
    for(int i=0; i<size; i++) freq[s[i]]++;
    for(int i=0; i<128; i++) if(freq[i]>1) return 0;
    for(int i=1; i<128; i++) freq[i]=freq[i]+freq[i-1]; // create pre_sum array
    char temp;
    for(int i=0; i<size; i++) {
        temp = s[i];
        fact /= (size-i);
        rank += fact*(freq[s[i]]-1);
        // adjustment(freq,temp);
        for(int k=s[i]; k<128; k++) freq[k]-=1;
    }
    return rank;
}

// { Driver Code Starts.


int main()
{
    string S;
    int t;
    cin>>t;
    while(t--)
    {
     
        cin>>S;
    cout<<findRank(S)<<endl;
    }
}
  // } Driver Code Ends
