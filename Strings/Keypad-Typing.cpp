// Problem URL :- https://practice.geeksforgeeks.org/problems/keypad-typing/0

#include<bits/stdc++.h>
using namespace std;
void keypadType(string s) {
    int a = 97;
    int slen = s.length();
    char temp;
    for(int i=0; i<slen; i++) {
        temp = (int)s[i]-97; // a=0, b=1, c=2
        if(temp<15) {
            cout<<(temp/3 + 2);
        } else if (temp<19){
            cout<<((temp-15)/4 + 7);
        } else if(temp<22) cout<<8;
        else cout<<9;
    }
}
int main() {
	//code
	int n; cin>>n;
	for(int p=0; p<n; p++) {
	    string s;
	    cin>>s;
	    keypadType(s);
	    cout<<endl;
	}
	return 0;
}
