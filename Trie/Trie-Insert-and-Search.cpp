/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/trie-insert-and-search/0
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
bool find(string input[], int n, string search) {
    struct trie* root = makeTrie(input,n);
    return isPresent(root,search);
}
int main() {
	//code
	int t;
	cin>>t;
	for(int cs=0; cs<t; cs++) {
	    int n;
	    cin>>n;
	    string input[n];
	    for(int i=0; i<n; i++) {
	        cin>>input[i];
	    }
	    string search;
	    cin>>search;
	    cout<<find(input,n,search)<<endl;
	}
	return 0;
}
