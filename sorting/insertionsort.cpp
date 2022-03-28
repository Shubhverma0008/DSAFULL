#include<iostream>
using namespace std;
void insertionsort(int A[],int n)
{
    int temp;
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        temp=A[i];
        while(temp<A[j]&&j>-1)
        {
            swap(A[j],A[j+1]);
            j--;
            
        }
        A[j+1]=temp;
    }

}
int main()
{
    int A[]={8,5,7,3,2};
    insertionsort(A,5);
    for(auto i:A)
    cout<<i<<" ";
}