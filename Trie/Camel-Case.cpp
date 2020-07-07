/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/camel-case0423/0
*/

#include<bits/stdc++.h>
using namespace std;
struct trie {
    struct trie* arr[26];    
    bool isEnd;
    trie() {
        for(int i=0; i<26; i++) arr[i]=nullptr;
        isEnd=false;
        // cc="";
    }
};
bool compare(pair<string,string> s1, pair<string,string> s2) { // first - uppercase, second - actual string
    int s1len = s1.first.length();
    int s2len = s2.first.length();
    for(int i=0; i<min(s1len,s2len); i++) {
        if(s1.first[i]!=s2.first[i]) return (s1.first[i]<s2.first[i]);
    }
    if(s1len != s2len) return (s1len<s2len);
    s1len = s1.second.length();
    s2len = s2.second.length();
    for(int i=0; i<min(s1len,s2len); i++) {
        if(s1.second[i]!=s2.second[i]) return (s1.second[i]<s2.second[i]);
    }
    return (s1len<s2len);
}
bool isAtBeginning(string end, string query) { // query should be at beginning of end
    if(end.length() < query.length()) return false;
    for(int i=0; i<query.length(); i++) {
        if(end[i]!=query[i]) return false;
    }
    return true;
}
void camelCase(string data[], int n, string query) {
    struct trie* root = new trie(); // using the new keyword is important
    // string upperCase[n];
    vector<pair<string,string>> upperCase;
    string res;
    trie *temp = root;
    pair<string, string> user;
    for(int i=0; i<n; i++) {
        temp = root;
        int size = data[i].length();
        char curr;
        string end="";
        for(int j=0; j<size; j++) {
            curr = data[i][j];
            // to handle upper case
            if(curr - 'a' < 0) {
                end += curr;
                continue;
            }
            if(temp->arr[curr-'a']==NULL) {
                temp->arr[curr-'a'] = new trie();
            }
            temp = temp->arr[curr-'a'];
        }
        temp->isEnd = true;
        if(isAtBeginning(end,query)) {
            user.first = end;
            user.second = data[i];
            upperCase.push_back(user);
        }
    }
    if(upperCase.size()==0) {
        cout<<"No match found"<<endl;
        return;
    } else {
        sort(upperCase.begin(),upperCase.end(),compare);
        for(int i=0; i<upperCase.size(); i++) {
            cout<<upperCase[i].second<<" ";
        }
        cout<<endl;
    }
}
int main() {
	//code
	int t;
	cin>>t;
	for(int cs=0; cs<t; cs++) {
	    int n;
	    cin>>n;
	    string data[n];
	    for(int i=0; i<n; i++) {
	        cin>>data[i];
	    }
	    string query;
	    cin>>query;
	    camelCase(data,n,query);
	}
	return 0;
}
