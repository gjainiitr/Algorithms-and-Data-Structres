// Problem URL :- https://practice.geeksforgeeks.org/problems/positive-negative-pair/0

#include <algorithm>
#include<vector>
using namespace std;
void posNegPair(int arr[], int n,int &count) {
    unordered_set<int> s;
    int pos,neg;
    vector<int> output;
    for(int i=0; i<n; i++) {
        pos = abs(arr[i]);
        if(s.find(pos)!=s.end()) output.push_back(pos);
        else s.insert(pos);
    }
    sort(output.begin(), output.end());
    for(auto it=output.begin(); it!=output.end(); it++) {
        cout<<(*it)<<" "<<-1*(*it)<<" ";
        count++;
    } 
}
int main() {
	//code
	int t; cin>>t;
	int count=0;
	for(int i=0; i<t; i++) {
	    int n; cin>>n; int arr[n];
	    for(int i=0; i<n; i++) cin>>arr[i];
	    count=0;
	    posNegPair(arr,n,count);
	    if(count==0) cout<<0;
	    cout<<endl;
	}
	return 0;
}
