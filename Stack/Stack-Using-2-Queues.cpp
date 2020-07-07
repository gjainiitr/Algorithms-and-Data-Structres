// Problem URL :- https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1

#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
        }
        cout<<endl;
    }
}
// } Driver Code Ends
/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
        // Your Code
        int temp;
        while(q1.empty()==false) {
            temp = q1.front();
            q1.pop();
            q2.push(temp);
        }
        q1.push(x);
        while(q2.empty()==false) {
            temp=q2.front();
            q2.pop();
            q1.push(temp);
        }
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
        // Your Code  
        if(q1.size()==0) return -1;
        int temp = q1.front();
        q1.pop();
        return temp;
}

