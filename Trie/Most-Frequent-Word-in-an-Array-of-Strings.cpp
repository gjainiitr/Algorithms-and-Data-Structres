/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/most-frequent-word-in-an-array-of-strings/0
*/

#include<bits/stdc++.h>
using namespace std;
struct trie {
    struct trie* arr[26];    
    bool isEnd;
    int count;
    trie() {
        for(int i=0; i<26; i++) arr[i]=nullptr;
        isEnd=false;
        count=0;
    }
};
string mostFrequent(string data[], int n) {
    struct trie* root = new trie(); // using the new keyword is important
    trie *temp = root;
    string ans="";
    int count[n]={0};
    int maxCount=0;
    for(int i=n-1; i>=0; i--) {
        temp = root;
        int size = data[i].length();
        char curr;
        for(int j=0; j<size; j++) {
            curr = data[i][j];
            if(temp->arr[curr-'a']==NULL) {
                temp->arr[curr-'a'] = new trie();
            }
            temp = temp->arr[curr-'a'];
            if(j==size-1) {
                temp->isEnd=true;    
                temp->count = temp->count+1;
                count[i] = temp->count;
                if(temp->count >= maxCount) {
                    maxCount = temp->count;
                }
            }
        }
    }
    for(int i=0; i<n; i++) {
        if(count[i]==maxCount) {
            ans = data[i];
        }
    }
    return ans;
}
int main() {
	//code
	int t;
	cin>>t;
	for(int cs=0; cs<t; cs++) {
	    int n;
	    cin>>n;
	    string data[n];
	    for(int i=0; i<n; i++) cin>>data[i];
	    cout<<mostFrequent(data,n)<<endl;
	}
	return 0;
}
