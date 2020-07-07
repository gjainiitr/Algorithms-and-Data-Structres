// Problem URL :- https://practice.geeksforgeeks.org/problems/median-of-two-sorted-arrays/0

#include<bits stdc++.h="">
using namespace std;

typedef long long ll;

int getMedian(ll a1[], ll a2[], int n1, int n2)
{
    int begin1 = 0, end1 = n1;
    
    while(begin1 <= end1)
    {
        ll i1 = (begin1 + end1)/2;
        ll i2 = (n1+n2+1)/2 - i1;
        
        ll min1 = (i1 == n1) ? INT_MAX : a1[i1];
        ll max1 = (i1 == 0)  ? INT_MIN : a1[i1-1];
        
        ll min2 = (i2 == n2) ? INT_MAX : a2[i2];
        ll max2 = (i2 == 0)  ? INT_MIN : a2[i2-1];
        
        if(max1 <= min2 && max2 <= min1)
        {
            if((n1+n2)%2 == 0)
            {
                return ((max(max1, max2) + min(min1, min2))/2);
            }
            else
            {
                return max(max1, max2);
            }
        }
        else if(max1 > min2)
        {
            end1 = i1-1;
        }
        else
        {
            begin1 = i1+1;
        }
    }
}
int main()
{
    int T;
    cin >> T;
    
    while(T--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        
        ll a1[n1], a2[n2];
        
        for(int i = 0; i < n1; i++)
        {
            cin >> a1[i];
        }
        for(int i = 0; i < n2; i++)
        {
            cin >> a2[i];
        }
        
        if(n1 < n2)
        {
            cout << getMedian(a1, a2, n1, n2) << endl;
        }
        else
        {
            cout << getMedian(a2, a1, n2, n1) << endl;
        }
    }
	return 0;
}
