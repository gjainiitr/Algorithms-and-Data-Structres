// Problem URL :- https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void reverseWords(char*);

/* Driver function to test above functions */
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[10000];
        cin >> s;
        reverseWords(s);
        cout<<endl;
    }
}// } Driver Code Ends

/*Function to reverse words*/
void reverseWords(char *s) {
    
    // Your code here
    bool noDot = false;
    int slen = strlen(s);
    string str(s),temp;
    int loc=0;
    int count = 0;
    if(str.find('.')<slen) {
        for(int i=slen-1; i>=0; i--) {
            if(str[i]!='.') {
                count++;
            } else {
                for(int j=i+1; j<=i+count; j++) {
                    temp+=str[j];
                }
            temp+='.';
            count=0;
        }
    }
        int k=0;
        while(str[k]!='.') {
            temp+=str[k];
            k++;
        }
        cout<<temp;
        } else
        cout<<str;

}

