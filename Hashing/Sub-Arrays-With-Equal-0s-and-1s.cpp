// Problem URL :- https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1

#include <bits/stdc++.h>
using namespace std;

long long int countSubarrWithEqualZeroAndOne(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	cout<< countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
// } Driver Code Ends
long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
{
    //Your code here
    int pre_sum=0,count=0;
    unordered_map<int, int> m;
    for(int i=0; i<n; i++) if(arr[i]==0) arr[i]=-1;
    for(int i=0; i<n; i++) {
        pre_sum+=arr[i];
        if(pre_sum==0) count++;
        auto it = m.find(pre_sum);
        if(it!=m.end()) count+=it->second;
        
        if(it==m.end()) m[pre_sum]=1;
        else m[pre_sum]=m[pre_sum]+1;
    }
    return count;
}

