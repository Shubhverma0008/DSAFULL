#include<iostream>
using namespace std;
void shellsort(int A[],int n)
{
    for(int gap=n/2;gap>=1;gap/=2)
    {
        for(int j=gap;j<n;j++)
       { int temp=A[j];
        int i=j-gap;
        while(i>=0&&temp<A[i])
        {
            A[i+gap]=A[i];
            i=i-gap;
        }
        A[i+gap]=temp;}
    }
}
int main()
{
    int A[]={3,5,10,4,2,6,12,16,8,13,9};
    shellsort(A,11);
    for(auto i:A)
    cout<<i<<" ";

}