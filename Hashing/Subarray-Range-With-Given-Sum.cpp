// Problem URL :- https://practice.geeksforgeeks.org/problems/subarray-range-with-given-sum0128/1

#include<bits/stdc++.h>
using namespace std;

int subArraySum(int arr[], int n, int sum);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,sum=0;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>sum;
	    cout<<subArraySum(arr, n, sum)<<endl;
	}
	return 0;
}// } Driver Code Ends



int subArraySum(int arr[], int n, int sum)
{
    //Your code here
    unordered_map<int,int> m;
    int curr_sum=0,count=0;
    for(int i=0; i<n; i++) {
        curr_sum+=arr[i];
        
        if(curr_sum==sum) count++;
        
        auto it = m.find(curr_sum-sum);
        if(it!=m.end()) {
            count+=it->second;
        }
        
        it = m.find(curr_sum);
        if(it==m.end()) m[curr_sum]=1;
        else m[curr_sum]=m[curr_sum] + 1;
        
    }
    return count;
}

