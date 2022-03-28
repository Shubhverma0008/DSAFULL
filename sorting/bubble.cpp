#include<iostream>
using namespace std;
int bubblesort(int A[],int n)
{  int l=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
            {swap(A[j],A[j+1]);
            l++;
            break;}
        }
        if(l==0)
        return 1;
        else return 0;

    }
}
int main()
{
    int A[]={1,2,3,4,5,6,7,8,9,10};
     cout<<bubblesort(A,10)<<endl;
    // for(auto x:A)
    // {
    //     cout<<x<<" ";
    // }
}