/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/renaming-cities2858/0
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
void makeCodes(string data[], int n) {
    struct trie* root = new trie(); // using the new keyword is important
    trie *temp = root;
    string result[n];
    
    for(int i=0; i<n; i++) {
        string ans = "";
        temp = root;
        int size = data[i].length();
        char curr;
        bool firstTime = true;
        for(int j=0; j<size; j++) {
            curr = data[i][j];
            if(temp->arr[curr-'a']==NULL) {
                if(firstTime==true) {
                    ans = ans + curr;
                    firstTime=false;
                }
                temp->arr[curr-'a'] = new trie();
            } else {
                ans = ans + curr;
            }
            temp = temp->arr[curr-'a'];
            if(j==size-1) {
                
                temp->count = temp->count+1;
            }
        }
        if(firstTime==true && temp->isEnd==true) {
            string num = to_string(temp->count);
            ans = ans+" "+num;    
        }
        temp->isEnd=true;
        result[i]=ans;
    }
    for(int i=0; i<n; i++) cout<<result[i]<<endl;
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
	    makeCodes(data,n);
	}
	return 0;
}
