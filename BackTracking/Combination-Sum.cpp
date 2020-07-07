/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends





int noOfWays(vector<int> arr,int i, int n, int sum, vector<vector<int>> &res, vector<int> curr) {
    if(sum==0) {
        sort(curr.begin(),curr.end());
        res.push_back(curr); // stringToVector returns vector<int>
        return 1;
    }
    if(i==n) return 0;
    int ans;
    if(sum-arr[i]>=0) {
        curr.push_back(arr[i]);
        ans += noOfWays(arr,i,n,sum-arr[i],res,curr);
        curr.erase(curr.end()-1);
    }
    ans += noOfWays(arr,i+1,n,sum,res,curr);
    return ans;
}
vector<vector<int> > combinationSum(vector<int> &arr, int sum) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    
    vector<int> temp;
    temp.push_back(arr[0]);
    for(int i=1; i<arr.size(); i++) {
        if(arr[i]==arr[i-1]) continue;
        temp.push_back(arr[i]);
    }
    arr.clear();
    // temp is sorted and duplicates are removed
    vector<int> curr;
    noOfWays(temp,0,temp.size(),sum,result,curr);

    return result;
}


// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        vector<vector<int> > result;
   		result=combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends
