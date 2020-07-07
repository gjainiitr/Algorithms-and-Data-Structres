/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/rearrange-characters5322/1
*/

#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;


 // } Driver Code Ends

struct key {
  char c;
  int freq;
  key(char ch, int f) {
      c = ch;
      freq = f;
  }
};
struct myCmp {
  bool operator()(struct key key1, struct key key2) {
      return (key1.freq < key2.freq);
  }  
};
string rearrangeString(string str){
	// Your code here
	unordered_map<char, int> m;
	int length = str.length();
	
	for(int i=0; i<length; i++) {
	    if(m.find(str[i])==m.end()) {
	        m[str[i]]=1;
	    } else {
	        m[str[i]] = m[str[i]]+1;
	    }
	}
	
	priority_queue<key,vector<key>, myCmp> pq;
	
	for(auto it=m.begin(); it!=m.end(); it++) {
	    pq.push(key(it->first,it->second));
	}
	
	key prev('#',-1);
	string res = "";
    while(pq.size()>0) {
        key temp = pq.top();
        pq.pop();
        temp.freq = temp.freq-1;
        res += temp.c;
        
        if(prev.freq>0) pq.push(prev);
        prev.c=temp.c;
        prev.freq = temp.freq;
    }
    
    if(str.length()>res.length()) return str;
    return res;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	cin.ignore(INT_MAX, '\n');
	while(t--)
	{
	    string str;
	    cin>>str;
	    str = rearrangeString(str);
	    int flag = 1;
	    if(str != "-1"){
    	for(int i=1;i<str.length();i++){
    		if(str[i-1]==str[i])
    			flag=0;
	    }
    	if(flag == 1)
    		cout<<"1\n";
    	else
    	    cout<<"0\n";
	    }
	    else
	        cout<<"0\n";
	}
return 0;
}  // } Driver Code Ends
