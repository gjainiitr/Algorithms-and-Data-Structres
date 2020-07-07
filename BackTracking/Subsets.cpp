/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/subsets-1587115621/1
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



unordered_set<string> m;
string makeString(vector<int> curr) {
    string res="";
    for(int i=0; i<curr.size(); i++) res += to_string(curr[i]) + " ";
    return res;
}
void printSubsets(vector<int> arr, int i, int n, vector<vector<int>> &result, vector<int> curr) {
    string str = makeString(curr);
    if(m.find(str)==m.end()) result.push_back(curr);
    m.insert(str);
    // if(i==n) {
    // if(i==n) {
    //     return;
    // }
    for(int index = i; index<n; index++) {
        curr.push_back(arr[index]);
        printSubsets(arr,index+1,n,result,curr);
        curr.pop_back();
    }
}
void func (vector <int> A)
{
    // Your code here
    if(A.size()==0) return;
    sort(A.begin(), A.end());
    // vector<int> temp;
    // temp.push_back(A[0]);
    // now just generate all the subsets
    vector<vector<int>> result;
    vector<int> curr;
    printSubsets(A,0, A.size(), result, curr);
    // cout<<result.size()<<endl;    
    
    // for(int i=0; i<result.size(); i++) {
    //     cout<<"(";
    //     int j=0;
    //     for(j=0; j<result[i].size()-1; j++) {
    //         cout<<result[i][j]<<" ";
    //     }
    //     if(result[i].size()!=0) cout<<result[i][j];
    //     cout<<")";
    // }
    
    for(int i=0; i<result.size(); i++) {
        int size = result[i].size();
        cout<<"(";
        for(int j=0; j<size-1; j++) cout<<result[i][j]<<" ";
        if(size>0) cout<<result[i][size-1];
        cout<<")";
    }
    m.clear();
    cout<<endl;
}

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        func(A);
        
    }
}	  // } Driver Code Ends
