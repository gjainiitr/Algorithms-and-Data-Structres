// Problem URL :- https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency-1587115621/1

#include <bits/stdc++.h>
using namespace std;


int a[1000000];

void sortByFreq(int arr[],int n);

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    
	    sortByFreq(a,n);
	    cout << endl;
	}
	
	return 0;
}

// } Driver Code Ends
//Complete this function
//The array is declared globally
int size;
bool myCompare(int a, int b) {
    if((a/size)==(b/size)) return a<b;
    else return a>b;
}
void sortByFreq(int arr[], int n) {
    size = arr[0];int temp; vector<int> v; unordered_map<int,int> m;
    // finding max element and adding all to hashmap
    for(int i=0; i<n; i++) {
        size=max(size,arr[i]);
        auto it = m.find(arr[i]);
        if(it==m.end()) {
            m[arr[i]]=1;
        } else m[arr[i]]=m[arr[i]]+1;
    }
    size+=1;
    for(auto it=m.begin(); it!=m.end(); it++) {
        temp = (it->first) + size*(it->second);
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), myCompare);
    
    // for(int i=0; i<n; ) {
    //     int j=i;
    //     while(j<n && (v[j]/size)==(v[i]/size)) {
    //         j++;
    //     }
    //     sort(v.begin()+i,v.begin()+j);
    //     i=j;
    // }
    
    for(auto p=v.begin(); p!=v.end(); p++) {
        temp = *p;
        for(int q=0; q<(temp/size); q++) {
            cout<<(temp%size)<<" ";
        }
    }
}
