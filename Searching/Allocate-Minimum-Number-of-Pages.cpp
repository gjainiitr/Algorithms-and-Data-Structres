// Problem URL :- https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages/0

#define ll long long
using namespace std;
bool isPossible(ll arr[], int n, int m, ll curr_min) {
    int curr_sum=0, studentsNeeded=1;
    for(int i=0; i<n; i++) {
        if(arr[i]>curr_min) return false;
        
        if(curr_sum + arr[i] > curr_min) {
            studentsNeeded +=1;
            curr_sum = arr[i];
        } else {
            curr_sum += arr[i];
        }
        if(studentsNeeded>m) return false;
    }
    return true;
}
ll minOfMaxLoad(ll arr[], int n, int m) {
    if(n<m) return -1;
    ll sum=0;
    for(int i=0; i<n; i++) sum+=arr[i];
    ll start=0,end=sum,res=sum;
    ll mid;
    while(start<=end) {
        mid = (start + end)/2;
        if(isPossible(arr,n,m,mid)) {
            end = mid-1;
            res = min(res,mid);
        } else {
            start = mid+1;
        }
    }
    return res;
}
int main() {
	//code
	int t;
	cin>>t;
	for(int cs=0; cs<t; cs++) {
	    int n;
	    cin>>n;
	    ll arr[n];
	    for(int i=0; i<n; i++) cin>>arr[i];
	    int m;
	    cin>>m;
	    cout<<minOfMaxLoad(arr,n,m)<<endl;
	}
	return 0;
}
