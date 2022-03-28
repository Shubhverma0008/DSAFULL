#include<iostream>
using namespace std;
int findmax(int A[],int n)
{
    int x=A[0];
    for(int i=1;i<n;i++)
    {
        if(A[i]>x)
        x=A[i];
    }
    return x;
}
void countsort(int A[],int n)
{
    int max=findmax(A,n);
    int *c;
    c=new int[max+1];
    for(int i=0;i<max+1;i++)
    {
        c[i]=0;
    }
    for(int i=0;i<n;i++)
    {
            c[A[i]]++;
    }
    int i=0,j=0;
    while(i<max+1)
    {
        if(c[i]>0)
        {
            A[j++]=i;
            c[i]--;
        }
        else i++;
    }
}
int main()
{
    int A[]={6,3,9,10,15,6,8,12,3,6};
    countsort(A,10);
    for(auto i:A)
    cout<<i<<" ";

}