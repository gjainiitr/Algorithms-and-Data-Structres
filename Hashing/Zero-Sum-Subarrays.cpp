// Problem URL :- https://practice.geeksforgeeks.org/problems/zero-sum-subarrays/0

#include<unordered_map>
using namespace std;
int zeroSum(int arr[], int n) {
    int count=0,pre_sum=0;
    unordered_map<int,int> m;
    for(int i=0; i<n; i++) {
        pre_sum+=arr[i];
        if(pre_sum==0) count++;
        
        auto it = m.find(pre_sum);
        if(it!=m.end()) count+=it->second;
        
        if(it==m.end()) m[pre_sum]=1;
        else it->second = it->second + 1;
    }
    return count;
}
int main() {
	//code
	int t; cin>>t;
	for(int i=0; i<t; i++) {
        int n; cin>>n; int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        cout<<zeroSum(arr,n);
	    cout<<endl;
	}
	return 0;
}
