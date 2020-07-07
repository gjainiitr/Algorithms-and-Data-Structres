// Problem URL :- https://practice.geeksforgeeks.org/problems/mean-and-median-1587115620/1

using namespace std;

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
int median(int A[],int N)
{
    int temp;
    sort(A,A+N);
    // if N is odd, give (N+1)/2th term i.e. index = (N-1)/2
    if(N%2 != 0) {
        return A[(N-1)/2];
    } else {
    // if N is even give avg of (N/2)-1th and (N/2)th term
        temp = (N/2);
        return {(A[temp-1] + A[temp])/2};
    }
}
int mean(int A[],int N)
{
    //your code here
    int sum = 0;
    for(int i=0; i<N; i++) {
        sum += A[i];
    }
    return sum/N;
}


int main()
{
    //testcase
    int T;
    cin>>T;
   
    //looping testcase
    while(T--)
    {
        //number of elements in array
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++){
            cin>>a[i];
        }
        cout<<mean(a,N)<<" "<<median(a,N)<<endl;
    }
    return 0;
}

