/*
	Problem URL:- https://practice.geeksforgeeks.org/problems/search-query-for-strings/0
*/
#include<bits/stdc++.h>
using namespace std;
struct trie {
    struct trie* arr[26];    
    bool isEnd;
    trie() {
        for(int i=0; i<26; i++) arr[i]=nullptr;
        isEnd=false;
    }
};
struct trie* makeTrie(string input[], int n) {
    struct trie* root = new trie(); // using the new keyword is important
    trie *temp = root;
    for(int i=0; i<n; i++) {
        temp = root;
        int size = input[i].length();
        char curr;
        for(int j=0; j<size; j++) {
            curr = input[i][j];
            if(temp->arr[curr-'a']==NULL) {
                temp->arr[curr-'a'] = new trie();
            }
            temp = temp->arr[curr-'a'];
            if(j==size-1) temp->isEnd=true;
        }
    }
    return root;
}
bool isPresent(struct trie* root, string word) {
    int size = word.length();
    struct trie* temp = root;
    for(int i=0; i<size; i++) {
        char curr = word[i];
        if(temp->arr[curr-'a'] == NULL) return false;
        temp = temp->arr[curr-'a'];
    }
    return temp->isEnd;
}
int main() {
	//code
	int t;
	cin>>t;
	for(int cs=0; cs<t; cs++) {
	    int n, queries;
	    cin>>n>>queries;
	    string data[n];
	    for(int i=0; i<n; i++) cin>>data[i];
	    struct trie* root = makeTrie(data,n);
	    string query;
	    for(int i=0; i<queries; i++) {
            cin>>query;
	        cout<<isPresent(root,query)<<endl;
	    }
	}
	return 0;
}
