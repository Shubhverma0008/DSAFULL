#include<iostream>
using namespace std;
int findmax(int A[],int n)
{
    int max=INT8_MIN;
    for(int i=0;i<n;i++)
    {
        if(max<A[i])
        max=A[i];
    }
    return max;
}
void count(int A[],int n)
{
    int max=findmax(A,n);
    int *c;
    c=new int[max+1];
    for(int i=0;i<max+1;i++)
    c[i]=0;
    for(int i=0;i<n;i++)
    c[A[i]]++;
    int i,j=0;
    i=0;
    while(i<max+1)
    {
        if(c[i]>0)
        {
            A[j++]=i;
            c[i]--;
        }
        else
        i++;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    cin>>A[i];
    count(A,n);
    for(auto i:A)
    cout<<i<<" ";
}