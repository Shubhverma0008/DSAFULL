#include<iostream>
using namespace std;
void selectionsort(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        int k=i;
        for(int j=i;j<n;j++)
        {
            if(A[j]<A[k])
            k=j;
        }
        swap(A[i],A[k]);
    }
}
int main()
{
    int A[]={8,6,3,2,5,4};
    selectionsort(A,6);
    for(int i=0;i<6;i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;

}