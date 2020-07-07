// Problem URL :- https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  cout<<findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}// } Driver Code Ends
int findLongestConseqSubseq(int arr[], int n)
{
  //Your code here
  unordered_set<int> s;
  for(int i=0; i<n; i++) {
      s.insert(arr[i]);
  }
  int count, curr,res=0;
  for(int i=0; i<n; i++) {
      count=0;
      curr=arr[i];
      if(s.find(curr-1)!=s.end()) continue;
      while(s.find(curr)!=s.end()) {
          count++;
          curr++;
      }
      res = count>res?count:res;
  }
  return res;
}
